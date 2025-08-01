# Detetion of Pressure Ulcer and Developent of Relief System

This project aims in developing a smart sheet that monitors the patient's pressure at the pressure ulcer prone regions with the help
of force sensor. The relief system is carried out with the help of vibration motors. Also Trained a YOLOv8n deep
learning model to predict the stages of the pressure ulcer
---

## Features

### Real-time Pressure Monitoring
- Utilizes square shaped force sensors interfaced with an ESP32 microcontroller.
- Continuously monitors pressure points across the patient's body.
- Activates a vibrating motor when pressure exceeds a predefined threshold.

### Machine Learning-Based Ulcer Detection
- Employs a YOLOv8 model to identify and classify pressure ulcer stages from wound images.
- Trained on a custom dataset.
- Supports caregivers in making informed decisions promptly.

---

## Project Structure

```
smart-pressure-ulcer-system/
│
├── hardware/
│   ├── esp32_code/               
│   └── circuit_diagram.png       
│
├── ml-model/
│   ├── yolov8_model/             
│   ├── dataset_info/            
│   └── training_logs/            
│
└── README.md
```

---

## Technology Stack

- **Microcontroller**: ESP32
- **Sensors**: Square Type Force Sensors
- **Actuation**: Vibrator Motor
- **Model**: YOLOv8 (Ultralytics)
- **Development Platform**: Google Colab

---

## Setup and Execution

### Machine Learning Inference
1. Clone the repository.
2. Install required package:
   ```bash
   pip install ultralytics
   ```
3. Run inference:
   ```python
   from ultralytics import YOLO
   model = YOLO('ml-model/yolov8_model/best.pt')
   results = model('path/to/image.jpg')
   ```

### ESP32 Firmware
- Upload the code from `hardware/esp32_code/` using Arduino IDE or PlatformIO.
- Connect sensors and relay according to the schematic in `circuit_diagram.png`.

---

## Author

**Pranav Hari Raja D**  
Email: pranavhariraja.d@gmail.com

---
