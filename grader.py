import sys
import subprocess
import os

def grade(task_path):
    if not os.path.isdir(task_path):
        print(f"❌ Hittade inte mappen: {task_path}")
        return

    test_file = os.path.join(task_path, "test.cpp")
    output_exe = os.path.join(task_path, "a.out")

    print(f"🔨 Kompilerar {task_path}...")
    
    # Vi kompilerar test.cpp (som i sin tur inkluderar student.cpp)
    # Vi lägger till -Wall för varningar och -fsanitize=address för att hitta minnesläckor (frivilligt men bra!)
    compile_cmd = ["g++", "-std=c++11", "-Wall", test_file, "-o", output_exe]
    
    compile_process = subprocess.run(compile_cmd, capture_output=True, text=True)
    
    if compile_process.returncode != 0:
        print("❌ Kompileringsfel!")
        print(compile_process.stderr)
        return

    print("🚀 Kompilering lyckades! Kör tester...\n")
    
    # Kör det kompilerade programmet
    run_process = subprocess.run([f"./{output_exe}"], capture_output=True, text=True)
    
    print(run_process.stdout)
    
    if run_process.returncode == 0:
        print("✅ Alla tester passerade! Snyggt jobbat.")
    else:
        print("❌ Testerna misslyckades. Se utskriften ovan för detaljer.")
        print(run_process.stderr)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Användning: python grader.py <sökväg_till_uppgift>")
        print("Exempel: python grader.py 170605/uppg4_monotonic")
        sys.exit(1)
        
    grade(sys.argv[1])