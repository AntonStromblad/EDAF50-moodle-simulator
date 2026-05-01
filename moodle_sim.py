import tkinter as tk
from tkinter import ttk, scrolledtext, messagebox
import subprocess
import os
import shutil

class MoodleSimulator:
    def __init__(self, root):
        self.root = root
        self.root.title("🐐 C++ Moodle-Simulator (Tenta-läge)")
        
        # Maximerar fönstret på Linux (kan behöva ändras till state('zoomed') på Windows)
        try:
            self.root.attributes('-zoomed', True)
        except:
            self.root.state('zoomed') # Fallback för Windows
            
        self.root.configure(bg="#2b2b2b")
        
        # --- Typsnitt ---
        ui_font = ("Helvetica", 16)     # Större text för gränssnittet
        code_font = ("Monospace", 18)   # Större och tydligare typsnitt för koden
        
        # --- Modern Styling (ttk) ---
        style = ttk.Style()
        if "clam" in style.theme_names():
            style.theme_use("clam")
            
        # Gör dropdown-menyerna mycket större och luftigare
        style.configure("TCombobox", font=ui_font, padding=8)
        style.configure("TFrame", background="#2b2b2b")
        
        # --- Hitta alla uppgifter uppdelat på Tenta ---
        self.exam_dict = self.find_tasks()
        
        # --- Tillstånd (State) ---
        self.is_practice_mode = False
        self.practice_task_path = "practice/uppg1_vector" # Den mapp som används i övningsläget
        
        # --- Layout: Top Frame ---
        top_frame = tk.Frame(root, pady=15, padx=20, bg="#2b2b2b")
        top_frame.pack(fill=tk.X)
        
        # 0. Läges-knapp (Tenta / Övning)
        self.mode_btn = tk.Button(top_frame, text="🏋️ Övningsläge", bg="#2196F3", fg="white", 
                                  activebackground="#1976D2", activeforeground="white", cursor="hand2",
                                  font=("Helvetica", 14, "bold"), relief=tk.FLAT, padx=15, pady=10, 
                                  command=self.toggle_mode)
        self.mode_btn.pack(side=tk.LEFT, padx=(0, 20))

        # --- Behållare för Tenta-läget (Dropdowns) ---
        self.exam_mode_frame = tk.Frame(top_frame, bg="#2b2b2b")
        self.exam_mode_frame.pack(side=tk.LEFT)
        
        # 1. Dropdown för Tenta
        tk.Label(self.exam_mode_frame, text="Tenta:", font=ui_font, bg="#2b2b2b", fg="#ffffff").pack(side=tk.LEFT)
        self.exam_var = tk.StringVar()
        self.exam_dropdown = ttk.Combobox(self.exam_mode_frame, textvariable=self.exam_var, state="readonly", font=ui_font, width=15)
        self.exam_dropdown.pack(side=tk.LEFT, padx=(10, 30))
        self.exam_dropdown.bind("<<ComboboxSelected>>", self.update_task_dropdown)
        
        # 2. Dropdown för Uppgift
        tk.Label(self.exam_mode_frame, text="Uppgift:", font=ui_font, bg="#2b2b2b", fg="#ffffff").pack(side=tk.LEFT)
        self.task_var = tk.StringVar()
        self.task_dropdown = ttk.Combobox(self.exam_mode_frame, textvariable=self.task_var, state="readonly", font=ui_font, width=30)
        self.task_dropdown.pack(side=tk.LEFT, padx=10)
        self.task_dropdown.bind("<<ComboboxSelected>>", self.load_code)

        # --- Behållare för Övningsläget (Rubrik) ---
        # --- Behållare för Övningsläget ---
        self.practice_mode_frame = tk.Frame(top_frame, bg="#2b2b2b")
        tk.Label(self.practice_mode_frame, text="🏋️ Övning:", font=ui_font, bg="#2b2b2b", fg="#4CAF50").pack(side=tk.LEFT, padx=10)
        
        self.practice_tasks = self.find_practice_tasks()
        self.practice_var = tk.StringVar()
        self.practice_dropdown = ttk.Combobox(self.practice_mode_frame, textvariable=self.practice_var, state="readonly", font=ui_font, width=30)
        self.practice_dropdown.pack(side=tk.LEFT, padx=10)
        self.practice_dropdown.bind("<<ComboboxSelected>>", self.load_practice_code)
        
        # Fyll dropdownen om det finns övningar
        if self.practice_tasks:
            self.practice_dropdown['values'] = self.practice_tasks
            self.practice_dropdown.current(0)

        # 3. Knappar (Submit & Reset)
        self.grade_btn = tk.Button(top_frame, text="🚀 Kör Tester", bg="#4CAF50", fg="white", 
                                   activebackground="#45a049", activeforeground="white", cursor="hand2",
                                   font=("Helvetica", 14, "bold"), relief=tk.FLAT, padx=20, pady=10, 
                                   command=self.run_grader)
        self.grade_btn.pack(side=tk.RIGHT, padx=5)

        self.reset_btn = tk.Button(top_frame, text="🔄 Återställ kod", bg="#f44336", fg="white", 
                                   activebackground="#d32f2f", activeforeground="white", cursor="hand2",
                                   font=("Helvetica", 14, "bold"), relief=tk.FLAT, padx=15, pady=10, 
                                   command=self.reset_code)
        self.reset_btn.pack(side=tk.RIGHT, padx=15)

        # --- Layout: Middle Frame (Code Editor) ---
        mid_frame = tk.Frame(root, padx=20, pady=10, bg="#2b2b2b")
        mid_frame.pack(fill=tk.BOTH, expand=True)
        
        tk.Label(mid_frame, text="Din kod i student.cpp (INGEN autocompletion!):", font=("Helvetica", 12), bg="#2b2b2b", fg="#aaaaaa").pack(anchor="w", pady=(0, 5))
        
        self.code_editor = scrolledtext.ScrolledText(mid_frame, font=code_font, bg="#1e1e1e", fg="#d4d4d4", 
                                                     insertbackground="white", relief=tk.FLAT, borderwidth=10, padx=10, pady=10)
        self.code_editor.pack(fill=tk.BOTH, expand=True)

        # --- Layout: Bottom Frame (Terminal) ---
        bot_frame = tk.Frame(root, padx=20, pady=15, bg="#2b2b2b")
        bot_frame.pack(fill=tk.BOTH, expand=True)
        
        tk.Label(bot_frame, text="Kompilator & Test-utskrift:", font=("Helvetica", 12), bg="#2b2b2b", fg="#aaaaaa").pack(anchor="w", pady=(0, 5))
        
        self.output_console = scrolledtext.ScrolledText(bot_frame, font=("Monospace", 14), bg="#0d0d0d", fg="#4af626", 
                                                        height=10, relief=tk.FLAT, borderwidth=10, padx=10, pady=10)
        self.output_console.pack(fill=tk.BOTH, expand=True)
        self.output_console.config(state=tk.DISABLED)

        # --- INITIERING AV FÖRSTA UPPGIFTEN ---
        exam_list = sorted(list(self.exam_dict.keys()))
        if exam_list:
            self.exam_dropdown['values'] = exam_list
            self.exam_dropdown.current(0)
            self.update_task_dropdown()

    def toggle_mode(self):
        """Växlar mellan Tenta-läge och Övningsläge"""
        self.is_practice_mode = not self.is_practice_mode

        if self.is_practice_mode:
            # Byt till Övningsläge
            self.root.title("🐐 C++ Moodle-Simulator (Övningsläge)")
            self.mode_btn.config(text="🎓 Tentaläge", bg="#9C27B0", activebackground="#7B1FA2")
            
            # Dölj dropdowns och visa övningsrubrik
            self.exam_mode_frame.pack_forget()
            self.practice_mode_frame.pack(side=tk.LEFT)
            
            # Ladda in övningskoden automatiskt
            self.load_practice_code()
        else:
            # Byt till Tentaläge
            self.root.title("🐐 C++ Moodle-Simulator (Tenta-läge)")
            self.mode_btn.config(text="🏋️ Övningsläge", bg="#2196F3", activebackground="#1976D2")
            
            # Dölj övningsrubrik och visa dropdowns
            self.practice_mode_frame.pack_forget()
            self.exam_mode_frame.pack(side=tk.LEFT)
            
            # Ladda in den valda tenta-uppgiften igen
            self.load_code()

    def find_tasks(self):
        """Skannar igenom mapparna och bygger en dictionary: { '170605': ['uppg1_ptr', 'uppg3_namelist'] }"""
        exams = {}
        for root_dir, dirs, files in os.walk('.'):
            if 'student.cpp' in files and 'test.cpp' in files:
                clean_path = root_dir.replace('\\', '/').removeprefix('./')
                parts = clean_path.split('/')
                # Ignorera warmup-mappen i dropdown-menyerna
                if len(parts) >= 2 and parts[0] != "practice":
                    exam_name = parts[0]
                    task_name = parts[1]
                    
                    if exam_name not in exams:
                        exams[exam_name] = []
                    exams[exam_name].append(task_name)
        
        for exam in exams:
            exams[exam].sort()
            
        return exams

    def find_practice_tasks(self):
        """Hittar alla mappar inuti 'warmup'"""
        tasks = []
        warmup_dir = 'practice'
        if os.path.exists(warmup_dir):
            for item in os.listdir(warmup_dir):
                item_path = os.path.join(warmup_dir, item)
                if os.path.isdir(item_path):
                    tasks.append(item)
        return sorted(tasks)
    
    def update_task_dropdown(self, event=None):
        """Uppdaterar den andra dropdownen baserat på vilken tenta som valts"""
        exam = self.exam_var.get()
        if not exam: return
        
        tasks = self.exam_dict.get(exam, [])
        self.task_dropdown['values'] = tasks
        
        if tasks:
            self.task_dropdown.current(0)
            self.load_code()
        else:
            self.task_var.set('')
            self.code_editor.delete("1.0", tk.END)

    def get_current_task_path(self):
        """Returnerar den aktuella mappen, beroende på vilket läge vi är i"""
        if self.is_practice_mode:
            task = self.practice_var.get()
            if not task: return None
            return os.path.join("practice", task)
            
        exam = self.exam_var.get()
        task = self.task_var.get()
        if not exam or not task: return None
        return os.path.join(exam, task)

    def load_practice_code(self, event=None):
        """Laddar in uppvärmningskoden baserat på dropdownen."""
        task_path = self.get_current_task_path()
        if not task_path: return
        
        os.makedirs(task_path, exist_ok=True)
        student_file = os.path.join(task_path, "student.cpp")
        
        if not os.path.exists(student_file):
            with open(student_file, "w", encoding="utf-8") as f:
                f.write("// Din uppvärmningskod här!\n#include <iostream>\n\nint main() {\n    std::cout << \"Redo för uppvärmning!\" << std::endl;\n    return 0;\n}\n")
                
        self.load_code_from_path(student_file)

    def load_code(self, event=None):
        """Laddar koden från dropdown-menyerna"""
        task_path = self.get_current_task_path()
        if not task_path: return
        student_file = os.path.join(task_path, "student.cpp")
        self.load_code_from_path(student_file)

    def load_code_from_path(self, student_file):
        """Hjälpfunktion för att ladda filinnehåll och hantera backups"""
        backup_file = student_file + ".bak"
        
        # Skapa en dold backup ifall användaren vill "Återställa" koden senare
        if not os.path.exists(backup_file) and os.path.exists(student_file):
            shutil.copy(student_file, backup_file)
            
        try:
            with open(student_file, "r", encoding="utf-8") as f:
                code = f.read()
            self.code_editor.delete("1.0", tk.END)
            self.code_editor.insert(tk.END, code)
            self.print_output(f"📂 Laddade filen: {student_file}")
        except Exception as e:
            self.print_output(f"❌ Fel vid laddning av fil: {e}")

    def reset_code(self):
        """Återställer koden från backup-filen"""
        task_path = self.get_current_task_path()
        if not task_path: return
        
        backup_file = os.path.join(task_path, "student.cpp.bak")
        
        if os.path.exists(backup_file):
            if messagebox.askyesno("Bekräfta återställning", "Är du säker på att du vill kasta din nuvarande kod och börja om från början?"):
                try:
                    with open(backup_file, "r", encoding="utf-8") as f:
                        original_code = f.read()
                    
                    self.code_editor.delete("1.0", tk.END)
                    self.code_editor.insert(tk.END, original_code)
                    self.print_output("🔄 Koden har återställts till ursprungsläget!")
                except Exception as e:
                    self.print_output(f"❌ Kunde inte återställa: {e}")
        else:
            self.print_output("⚠️ Ingen backup hittades. Kanske är detta redan originalkoden?")

    def run_grader(self):
        task_path = self.get_current_task_path()
        if not task_path: return

        student_file = os.path.join(task_path, "student.cpp")
        code = self.code_editor.get("1.0", tk.END)
        try:
            with open(student_file, "w", encoding="utf-8") as f:
                f.write(code)
        except Exception as e:
            self.print_output(f"Kunde inte spara filen: {e}")
            return

        self.print_output(f"🔨 Kompilerar och kör tester för {task_path}...\n")
        self.root.update()
        
        try:
            process = subprocess.run(["python3", "grader.py", task_path], capture_output=True, text=True)
            full_output = process.stdout + "\n" + process.stderr
            self.print_output(full_output)
        except Exception as e:
            self.print_output(f"Kunde inte köra grader.py. Fel: {e}\n(Kontrollera att du kör kommandot 'python' eller 'python3' beroende på OS)")

    def print_output(self, text):
        self.output_console.config(state=tk.NORMAL)
        self.output_console.delete("1.0", tk.END)
        self.output_console.insert(tk.END, text)
        self.output_console.config(state=tk.DISABLED)

if __name__ == "__main__":
    root = tk.Tk()
    app = MoodleSimulator(root)
    root.mainloop()