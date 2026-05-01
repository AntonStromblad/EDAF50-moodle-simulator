🐐 C++ Moodle-Simulator (EDAF50)

Ett totalt vibekodat hjälpverktyg till kursen EDAF50

En lokal övningsmiljö och autograder för att träna inför C++ tentamen. Simulatorn efterliknar den riktiga examensmiljön (Moodle) genom att erbjuda en rå texteditor **helt utan autocompletion**, för att tvinga dig att bygga muskelminne för syntax, minneshantering och STL-algoritmer.

## ✨ Funktioner

* **Tenta-läge:** Välj bland gamla tentor och specifika uppgifter direkt i en rullgardinsmeny.
* **Övningsläge:** Mjukstarta med grundläggande C++ koncept (Klasser, Rule of Three, etc.).
* **Inbyggd Autograder:** Kompilerar din kod och kör dedikerade enhetstester med ett knapptryck.
* **Återställ Kod:** Råkade du radera för mycket? Återställ koden till startläget med ett klick.
* **Ingen Autocomplete:** Samma tuffa villkor som på den riktiga tentan!

---

## 🛠️ Systemkrav & Beroenden

För att köra simulatorn behöver du:
1. **Python 3.x**
2. **En C++ Kompilator:** T.ex. `g++` (Linux/Windows med MinGW) eller `clang++` (Mac). Kompilatorn måste finnas i din system-PATH.
3. **Tkinter:** Pythons inbyggda bibliotek för grafiska gränssnitt (GUI).

### 🖥️ Felsökning för GUI (Tkinter)

Beroende på vilket operativsystem du använder kan du behöva justera vissa saker för att fönstret ska fungera felfritt:

**För Linux (Ubuntu/Debian):**
Python på Linux kommer inte alltid med Tkinter förinstallerat. Om programmet kraschar vid start, kör detta i terminalen:
sudo apt-get update
sudo apt-get install python3-tk



### Maximerat fönster (Linux vs Windows/Mac):

Simulatorn försöker automatiskt starta i helskärm. Koden hanterar detta via en try/except-block i moodle_sim.py:

    Linux använder: self.root.attributes('-zoomed', True)

    Windows använder: self.root.state('zoomed')
    Skulle fönstret bete sig konstigt vid start, kan du kommentera bort dessa rader i moodle_sim.py (runt rad 14).

### Problem med kompilering (Kommando-namn):
Simulatorn anropar grader.py via kommandot python3 grader.py. Om du sitter på Windows och din Python-installation bara heter python, kan du behöva ändra raden:
process = subprocess.run(["python3", "grader.py", task_path]...
till:
process = subprocess.run(["python", "grader.py", task_path]... i moodle_sim.py.


### 🚀 Installation & Körning

    Klona repot till din dator:
    Bash

    git clone <din-github-länk-här>
    cd <mappens-namn>

    Starta simulatorn:
    Bash

    python3 moodle_sim.py
    # eller 'python moodle_sim.py' på Windows
