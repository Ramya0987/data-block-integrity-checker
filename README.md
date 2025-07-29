# 🧱 Data Block Integrity Checker

This project simulates data corruption and verifies block-level integrity using C++. It includes a Python notebook for visualizing validation results in tabular format.

---

## 🚀 Features

- Simulates data corruption in pseudo-distributed storage
- Validates each block using checksum logic
- Identifies corrupted blocks and flags them
- Optionally auto-corrects blocks (future feature)
- Displays report using `pandas` in a Colab/Python notebook

---

## 🛠 Tech Stack

- **C++** — Core logic for corruption simulation and block validation
- **Python (pandas)** — Tabular visualization of validation results
- **Colab Notebook** — For easy result inspection

---

## 📁 Files

| File                       | Description                              |
|----------------------------|------------------------------------------|
| `block_checker.cpp`        | C++ logic for data corruption & checksum |
| `sample_data.txt`          | Simulated data file                      |
| `validation_report.csv`    | Output from validation (optional)        |
| `block_validation_report.ipynb` | Python notebook to display results   |

---

## 🧪 Sample Output

```plaintext
Corrupted block indices: [13, 5, 11]

Block Index | Is Valid
------------|----------
0           | True
1           | True
...         | ...
13          | False


👤 Author
Ramya Vathsalya Perikala
LinkedIn | GitHub
📜 License
This project is licensed under MIT — feel free to use or contribute!
