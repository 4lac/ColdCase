# 🧊 ColdCase — Digital Forensic Code Scanner
<p align="center">
  <img src="coldcaselogo.png" alt="ColdCase Logo" width="250"/>
</p>

ColdCase is a digital forensics–themed source‑code scanner written in C.  
It analyzes files line‑by‑line like a detective investigating a cold case, searching for suspicious traces such as:

- TODO comments  
- FIXME notes  
- Exposed passwords  
- Risky or deprecated functions  
- Unused or legacy code  
- Metadata anomalies  

ColdCase generates a narrative forensic report with color‑coded issue types and a risk assessment.  
Designed and narrated by **Reyof**.

---

## 📁 Project Structure
ColdCase/ ├── coldcase.c ├── metadata.c ├── scanner.c ├── report.c ├── status.c ├── include/ │    ├── coldcase.h │    ├── metadata.h │    ├── scanner.h │    ├── report.h │    ├── status.h ├── tests/ │    ├── suspect.c      (test file – not part of the tool) │    ├── suspect1.c     (test file – not part of the tool) ├── LICENSE └── README.md

> **Note:**  
> Files inside `tests/` are **not** part of the build.  
> They are used only as input samples for ColdCase to analyze.

---

## ⚙️ Building the Tool

### 🟦 Windows (MSYS2 / MinGW‑w64)

1. Open **MSYS2 MinGW 64-bit** terminal  
2. Navigate to the project folder:
cd /c/Users/YourName/ColdCase
3. Compile:
gcc coldcase.c metadata.c report.c scanner.c status.c -o coldcase.exe
4. Run:
./coldcase.exe

---

### 🟩 Kali Linux / Ubuntu / WSL

1. Install GCC (if needed):
sudo apt update sudo apt install gcc
2. Navigate to the project folder:
cd ~/ColdCase
3. Compile:
gcc coldcase.c metadata.c report.c scanner.c status.c -o coldcase
4. Run:
./coldcase

---

## 🔍 How to Use ColdCase

After running the tool, it will ask:
Enter the name of the file to investigate:

Type the name of any file you want to scan:
suspect.c


ColdCase will generate a full forensic-style report including:

- Issue count  
- Risk level  
- File age  
- Suspicious patterns  
- TODO / FIXME traces  
- Exposed secrets  
- Deprecated logic  

---

## 🧪 Test Files

The project includes sample files inside `tests/`:

- suspect.c  
- suspect1.c  

These files intentionally contain:

- TODO  
- FIXME  
- Exposed passwords  
- Unsafe functions  
- Legacy code  

They are **not** part of the tool — they are used only for testing ColdCase’s detection engine.

---

## 📜 License

This project is released under the **MIT License** (or GPL‑3.0 if you choose).  
Make sure your LICENSE file matches your choice.

---

## 🧊 Author

Developed and narrated by **Reyof**.  
A blend of digital forensics and C programming.
