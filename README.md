# ✍️ Handwritten Digits Identification (C / C++)

**Course:** Programming Workshop in C & C++  
**Institution:** The Hebrew University of Jerusalem  
**Assignment #4 – Neural Network Implementation**

---

## 🎯 Overview
This assignment implements a **feed-forward neural network** for recognizing **handwritten digits (0–9)** from grayscale images.  
It was designed for students in the **Programming in C/C++ workshop**, combining object-oriented programming, operator overloading, and numerical computing.  
Although simplified, the model achieves about **96% accuracy** when using the provided pre-trained weights and biases.

---

## 🧩 Concept
The exercise introduces students to:
- The **basics of C++ classes**, constructors, destructors, and operator overloading.  
- The **Rule of Three**, **references**, and **exception handling**.  
- Building a **matrix math library** from scratch (no STL allowed).  
- Implementing a **4-layer neural network** manually using matrices and activation functions.

---

## 🧠 Theoretical Background
A **fully-connected feed-forward neural network** processes an input vector x through successive layers:

\[ y = f(Wx + b) \]

where:
- W: weight matrix  
- b: bias vector  
- f: activation function  

The network’s final output is a **probability distribution** over digits 0–9, produced by a **Softmax** layer.

---

## ⚙️ Network Architecture

| Layer | Type | Activation | Dimensions (Weights × Bias) |
|:------|:------|:------------|:-----------------------------|
| 1 | Dense (Input → Hidden) | ReLU | 784 × 128, bias 128 |
| 2 | Dense (Hidden) | ReLU | 128 × 64, bias 64 |
| 3 | Dense (Hidden) | ReLU | 64 × 20, bias 20 |
| 4 | Dense (Output) | Softmax | 20 × 10, bias 10 |

Pipeline:
```
r1 = ReLU(W1·x + b1)
r2 = ReLU(W2·r1 + b2)
r3 = ReLU(W3·r2 + b3)
r4 = Softmax(W4·r3 + b4)
```

Each image is a **28×28 grayscale matrix** (values in [0,1]), flattened to a vector of size 784.  
The output is a probability vector of length 10, where the **index of the maximum value** corresponds to the predicted digit.

---

## 🧮 Activation Functions
Implemented manually in `Activation.cpp`:

- **ReLU(x)** = max(0, x)  
  Applies element-wise, ensuring non-linearity.  

- **Softmax(xᵢ)** = eˣⁱ / Σₖ eˣᵏ  
  Converts raw outputs into a normalized probability distribution.

---

## 🧰 Classes Implemented
All classes were coded **from scratch**, with no use of STL containers like `std::vector`.

| Class | Purpose | Highlights |
|:------|:---------|:-----------|
| `Matrix` | Handles all matrix operations | Operator overloading (`+`, `*`, `()`, `[]`, `<<`, `>>`), transpose, vectorize, dot, norm |
| `Activation` | Static functions for ReLU and Softmax | Uses function pointers for flexibility |
| `Dense` | Represents a single neural network layer | Holds weights, bias, and activation; applies layer computation |
| `MlpNetwork` | Combines all four layers into the full model | Executes inference and returns the predicted digit |

---

## 💾 Input and Output

### **Input**
The program receives **8 binary files** containing the pre-trained weights and biases:
```
w1 w2 w3 w4 b1 b2 b3 b4
```

Then it waits for **user input** — a path to a binary image file.  
The image is read, flattened into a matrix, and fed into the network.

### **Output**
- Prints the **predicted digit** and the **confidence level** (probability).  
- Continues until user types `q`, which exits with code `0`.

Example:
```
$ ./mlpnetwork w1 w2 w3 w4 b1 b2 b3 b4
Please enter image path: images/img_42.bin
Network output: 7 (confidence 0.90)
Please enter image path: q
```

---

## 🧱 File Structure
```
├── Matrix.h / Matrix.cpp           # Matrix implementation
├── Activation.h / Activation.cpp   # ReLU & Softmax
├── Dense.h / Dense.cpp             # Neural network layer
├── MlpNetwork.h / MlpNetwork.cpp   # 4-layer neural network
├── main.cpp                        # Loads weights, runs inference
├── Makefile                        # Compilation configuration
├── plot_img.py                     # Utility for displaying images
└── Ex4.pdf                         # Full exercise description (this document)
```

---

## ⚙️ Compilation and Execution

### 1️⃣ Build
Compile the program using the provided Makefile:
```bash
make mlpnetwork
```

### 2️⃣ Run
Run the executable with all weight and bias file paths:
```bash
./mlpnetwork w1 w2 w3 w4 b1 b2 b3 b4
```

Then input the path to a digit image file (binary format).

### 3️⃣ Exit
Type `q` to quit the program.  
Return code `0` indicates successful termination.

---

## 🧨 Error Handling
Exception handling uses standard C++ exceptions:

| Error Type | Exception | Description |
|-------------|------------|-------------|
| Invalid matrix size | `std::length_error` | Mismatched dimensions |
| Out of range access | `std::out_of_range` | Index out of range |
| Invalid user input | `std::runtime_error` | Bad input file |
| Memory allocation failure | `std::bad_alloc` | Raised automatically |

---

## 🧪 Testing and Validation
- Students were encouraged to test their code using **Valgrind** to ensure **no memory leaks**.  
- Code had to compile and run **without warnings or STL usage**.  
- Expected network accuracy ≈ **96%**, small deviations allowed due to floating-point arithmetic.

---

## 📚 Learning Objectives
- Implementing OOP and polymorphism in C++.  
- Practicing **operator overloading** and **exception handling**.  
- Understanding the structure of a simple **feed-forward neural network**.  
- Writing modular, reusable, and readable C++ code without STL.

---

## 🧑‍🏫 Author & Instruction Context
This project was developed and supervised by **Assaf Gozlan** as part of his teaching duties  
in the *C / C++ Programming Workshop* course at **The Hebrew University of Jerusalem**.  
The exercise was distributed to students in May 2022 and served as an introduction to  
practical neural network implementation in native C++.

---

© 2022 — Hebrew University of Jerusalem, Department of Computer Science
