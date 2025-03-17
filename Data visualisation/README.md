# **BioSafe Monitor - Step-by-Step Guide**  

## **Introduction**  
BioSafe Monitor is a real-time gas monitoring system designed to detect and predict harmful gas concentrations in environments like sewer and septic tanks. It helps in:  
- Monitoring gas levels in real time  
- Detecting abnormal gas concentration spikes using machine learning  
- Predicting future gas concentration levels using deep learning  

This guide explains how to set up and use the project, even if you are new to coding.  

---

## **1. What You Need Before Starting**  

Before running the project, make sure you have the following installed on your computer:  

1. **Python 3.8 or newer**  
   - To check if Python is installed, open a terminal (Command Prompt or Terminal) and type:  
     ```
     python --version
     ```
   - If Python is not installed, download and install it from [python.org](https://www.python.org/downloads/).  

2. **Git** (to download the project files)  
   - To check if Git is installed, type:  
     ```
     git --version
     ```
   - If it is not installed, download and install it from [git-scm.com](https://git-scm.com/downloads).  

3. **A Code Editor (Optional, but Recommended)**  
   - You can use Notepad, but it’s easier to work with a code editor like [VS Code](https://code.visualstudio.com/) or [PyCharm](https://www.jetbrains.com/pycharm/).  

---

## **2. Downloading the Project Files**  

The project files are stored in an online repository. You need to download them to your computer using Git.  

### **Steps to Download the Project**  

1. Open a **terminal or command prompt** on your computer.  
2. Run the following command to download the project:  
   ```
   git clone https://github.com/your-username/biosafe-monitor.git
   ```
3. After downloading, navigate to the project folder by typing:  
   ```
   cd biosafe-monitor
   ```

If you prefer to download the files manually, go to the repository link, click on the **"Download ZIP"** button, extract the ZIP file, and open the folder.  

---

## **3. Setting Up the Project**  

To avoid conflicts with other Python programs on your computer, it’s recommended to set up a **virtual environment** where all the required packages will be installed.  

### **Creating a Virtual Environment**  

1. Open the terminal and make sure you are inside the project folder.  
2. Run the following command to create a virtual environment:  

   - **Windows**  
     ```
     python -m venv venv
     venv\Scripts\activate
     ```
   - **Mac/Linux**  
     ```
     python -m venv venv
     source venv/bin/activate
     ```

Once activated, you will see `(venv)` before your terminal prompt, which means the virtual environment is active.  

---

### **Installing Required Packages**  

The project needs some additional Python libraries. They are listed in the `requirements.txt` file.  

1. Install the necessary dependencies by running:  
   ```
   pip install -r requirements.txt
   ```
2. If any module is missing and you see an error like `ModuleNotFoundError: No module named 'xyz'`, install it manually using:  
   ```
   pip install module_name
   ```
   (Replace `module_name` with the missing module shown in the error.)  

---

## **4. Understanding the Dataset**  

The project uses a **CSV file** that contains gas concentration readings over time. The file is already included in the `/data` folder and is named **`gas_readings.csv`**.  

### **What If You Want to Use Your Own Data?**  

If you want to replace the provided dataset with your own, make sure the data follows this format:  

| Timestamp          | H₂S | CH₄ | NH₃ | CO | SO₂ |  
|--------------------|----:|----:|----:|---:|----:|  
| 2025-03-17 10:00  | 5.2 | 2.8 | 1.0 | 3.2 | 0.5 |  
| 2025-03-17 10:01  | 6.1 | 3.5 | 1.5 | 4.1 | 0.7 |  

Save this data as a **CSV file** and place it inside the `/data` folder. Make sure the column names match exactly as shown above.  

---

## **5. Running the Project**  

Once everything is set up, you can run different parts of the project depending on what you want to do.  

---

### **1. Running the Real-Time Monitoring System**  

This program reads gas concentration data and checks if any gas level is too high. If it detects dangerous levels, it will trigger an alert.  

#### **To run it:**  
1. Make sure your virtual environment is activated.  
2. Run the following command:  
   ```
   python src/Real_time_monitoring_for_anomaly.py
   ```
3. The program will start reading gas levels from the CSV file and show the status in the terminal.  
4. If a gas level is above the safe limit, the program will print a **warning message**.  

---

### **2. Running the Anomaly Detection System**  

This program uses machine learning to detect unusual gas concentration spikes. It is useful to identify sudden hazardous gas releases.  

#### **To run it:**  
1. Activate your virtual environment.  
2. Run:  
   ```
   python src/isolation_using_anomaly.py
   ```
3. The program will process the data and highlight any anomalies.  

---

### **3. Running the Gas Concentration Prediction System**  

This program predicts future gas levels using an LSTM model. It helps in forecasting dangerous gas build-ups.  

#### **To run it:**  
1. Activate your virtual environment.  
2. Run:  
   ```
   python src/using_lstm_to_predict_conc.py
   ```
3. The program will analyze past gas levels and provide predictions for the future.  

---

## **6. Troubleshooting and Common Issues**  

**Problem:** `pip install -r requirements.txt` gives an error  
- **Solution:** Try installing the missing module manually using:  
  ```
  pip install module_name
  ```

**Problem:** `python: command not found`  
- **Solution:** Try using `python3` instead of `python` in all commands.  

**Problem:** CSV file not found  
- **Solution:** Make sure `gas_readings.csv` is inside the `/data` folder. If you created a new dataset, check that the column names match exactly.  

---
