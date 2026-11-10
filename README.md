# 🧊 ColdCase — Digital Forensic Code Scanner
<p align="center">
  <img src="coldcaselogo.png" alt="ColdCase Logo" width="250"/>
</p>

ColdCase is a digital forensics–themed source‑code scanner written in C.  
It analyzes files line‑by‑line like a detective investigating a cold case, searching for suspicious traces such as:

- TODO comments  
- FIXME notes  
- Exposed passwords  
- Use of `eval`  

It also collects the file's metadata — size, last modification time, and file age.

ColdCase generates a narrative forensic report with color‑coded issue types and a status verdict based on how long the file has been untouched.  
Designed and narrated by **Reyof**.

---

## 📁 Project Structure

```
ColdCase/
├── coldcase.c / coldcase.h    → entry point and shared definitions
├── scanner.c  / scanner.h     → line-by-line detection engine
├── metadata.c / metadata.h    → file size, timestamps, and age
├── status.c   / status.h      → file status verdict
├── report.c   / report.h      → color-coded forensic report
├── suspect.c                  (test file – not part of the tool)
├── suspect1.c                 (test file – not part of the tool)
├── LICENSE
└── README.md
```

> **Note:**  
> `suspect.c` and `suspect1.c` are **not** part of the build.  
> They are used only as input samples for ColdCase to analyze.

---

## ⚙️ Building the Tool

### 🟦 Windows (MSYS2 / MinGW‑w64)

1. Open **MSYS2 MinGW 64-bit** terminal  
2. Navigate to the project folder:
   ```bash
   cd /c/Users/YourName/ColdCase
   ```
3. Compile:
   ```bash
   gcc coldcase.c metadata.c report.c scanner.c status.c -o coldcase.exe
   ```
4. Run:
   ```bash
   ./coldcase.exe
   ```

---

### 🟩 Kali Linux / Ubuntu / WSL

1. Install GCC (if needed):
   ```bash
   sudo apt update
   sudo apt install gcc
   ```
2. Navigate to the project folder:
   ```bash
   cd ~/ColdCase
   ```
3. Compile:
   ```bash
   gcc coldcase.c metadata.c report.c scanner.c status.c -o coldcase
   ```
4. Run:
   ```bash
   ./coldcase
   ```

---

## 🔍 How to Use ColdCase

After running the tool, it will ask:
```
Enter the name of the file to investigate:
```

Type the name of any file you want to scan:
```
suspect.c
```

ColdCase will generate a full forensic-style report including:

- File size and last modification time  
- Number of issues found  
- File status — from **Hot** (recently modified) to **Frozen** (untouched for months)  
- Each issue with its line number, type, and content, color-coded by type  

---

## 🧪 Test Files

The project includes two sample files:

- suspect.c  
- suspect1.c  

These files intentionally contain TODO and FIXME notes, exposed passwords, and other suspicious code, so you can see ColdCase's detection engine in action.

They are **not** part of the tool.

---

## 📜 License

This project is licensed under the **GNU General Public License v3.0** — see the [LICENSE](LICENSE) file for details.

---

## 🧊 Author

Developed and narrated by **Reyof**.  
A blend of digital forensics and C programming.
