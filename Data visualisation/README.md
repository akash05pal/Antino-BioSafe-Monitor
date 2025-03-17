## 📌 **BioSafe Monitor**  
**Real-time monitoring and anomaly detection for harmful gases in sewer and septic tanks.**  

### 🏗 **Project Structure**  
```
biosafe-monitor/
│── data/
│   ├── gas_readings.csv          # Sample gas concentration data
│
│── src/
│   ├── Real_time_monitoring_for_anomaly.py  # Real-time gas monitoring with alert system
│   ├── isolation_using_anomaly.py           # Anomaly detection using Isolation Forest
│   ├── using_lstm_to_predict_conc.py        # LSTM-based gas concentration prediction
│
│── requirements.txt  # Required dependencies
│── README.md         # Project documentation
```

---

## 🌟 **Overview**  
BioSafe Monitor is designed to **analyze and predict gas concentration levels** in hazardous environments like sewer and septic tanks. It helps in:  
✔ **Real-time monitoring** of gas levels  
✔ **Anomaly detection** using ML techniques  
✔ **Predicting gas concentrations** using LSTM  

The project uses **Python, Pandas, Matplotlib, Scikit-learn, TensorFlow, and more** to provide an intuitive gas monitoring system. 🚀  

---

## ⚙ **Installation**  
### Prerequisites  
Make sure you have **Python 3.8+** installed.  

### Step 1️⃣: Clone the repository  
```bash
git clone https://github.com/your-username/biosafe-monitor.git
cd biosafe-monitor
```

### Step 2️⃣: Create a Virtual Environment (Recommended)  
```bash
python -m venv venv
source venv/bin/activate  # On macOS/Linux
venv\Scripts\activate  # On Windows
```

### Step 3️⃣: Install Dependencies  
```bash
pip install -r requirements.txt
```

---

## 🚀 **Usage**  
### 1️⃣ **Real-Time Monitoring with Alerts**  
```bash
python src/Real_time_monitoring_for_anomaly.py
```
- Reads **gas_readings.csv** from `/data/`
- Monitors **H₂S, CH₄, NH₃, CO, SO₂** levels  
- Triggers alerts if any gas crosses the threshold 🚨  

### 2️⃣ **Anomaly Detection using Isolation Forest**  
```bash
python src/isolation_using_anomaly.py
```
- Identifies unusual gas concentration spikes 📈  

### 3️⃣ **Gas Concentration Prediction using LSTM**  
```bash
python src/using_lstm_to_predict_conc.py
```
- Uses an **LSTM model** to forecast gas levels  

---

## 📂 **Dataset**  
- The gas concentration data is stored in `/data/gas_readings.csv`  
- Ensure the dataset follows this format:  

| Timestamp          | H2S | CH4 | NH3 | CO | SO2 |
|--------------------|----:|----:|----:|---:|----:|
| 2025-03-17 10:00  | 5.2 | 2.8 | 1.0 | 3.2 | 0.5 |
| 2025-03-17 10:01  | 6.1 | 3.5 | 1.5 | 4.1 | 0.7 |

---

## 🛠 **Troubleshooting**  
- **Issue:** `ModuleNotFoundError` → Install dependencies: `pip install -r requirements.txt`  
- **Issue:** Graph updates too fast → Adjust `interval=500` in the animation function  
- **Issue:** No sound alert? Ensure `winsound` (Windows) or `tkinter` (Linux/macOS) is working  

---

## 🤝 **Contributing**  
Feel free to **fork the repo, improve the project, and submit a PR!** 🚀  

1. Fork the repository  
2. Create a feature branch (`git checkout -b feature-name`)  
3. Commit changes (`git commit -m "Added feature XYZ"`)  
4. Push to your branch (`git push origin feature-name`)  
5. Open a pull request  

---

## 📜 **License**  
This project is open-source under the **MIT License**.  

---
