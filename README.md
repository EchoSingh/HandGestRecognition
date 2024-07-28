# HandGestRecognition ✋

Welcome to the **HandGestRecognition** project! This project uses OpenCV to perform hand gesture recognition using a webcam. Let's get started with some cool hand gestures! 🤘

## 📁 Project Structure
```plaintext
📂 HandGestRecognition
├── 📂 src
│   ├── 📂 include
│   │   ├── HandGestureRecognition.hpp
│   │   └── Utils.hpp
│   ├── HandGestureRecognition.cpp
│   ├── Utils.cpp
│   └── main.cpp
├── README.md
└── LICENSE
```
- **src/main.cpp**: The main entry point for the application. 🚀
- **src/HandGestureRecognition.cpp**: Implementation of the hand gesture recognition logic. ✋
- **src/Utils.cpp**: Utility functions used in the project. 🛠️
- **src/include/HandGestureRecognition.hpp**: Header file for hand gesture recognition. 📄
- **src/include/Utils.hpp**: Header file for utility functions. 📄

## 🚀 Getting Started

### Prerequisites

Make sure you have the following installed:
- **VisualStudio** <img src="https://visualstudio.microsoft.com/wp-content/uploads/2021/10/Product-Icon.svg" alt="Visual Studio" width="25" height="25">
  - Download Visual Studio from [LINK](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false)
- **OpenCV** 📦
  - Download OpenCV 4.10.0 for Windows [LINK](https://opencv.org/releases/) and extract it to `C:\opencv`.
  - Add `C:\opencv\build\bin` to your system's PATH environment variable.

### Building the Project

1. Open your Visual Studio project. 🖥️
2. Go to `Project -> Properties`. ⚙️
3. Navigate to `VC++ Directories` and add the paths to your OpenCV `include` and `lib` directories. 📂
4. Under `Linker -> Input`, add the OpenCV libraries you need (for debug mode : `opencv_world4100d.lib`). 📚

### Running the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/EchoSingh/HandGestRecognition.git
   cd HandGestRecognition
    ```
2. Build and run the project in Visual Studio. 🛠️🎬

Enjoy recognizing hand gestures with your webcam! 📸👌
Feel free to contribute and improve the project. Happy coding! 😊
