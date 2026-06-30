# Smart E-Challan Management System

An object-oriented traffic challan (violation ticket) management system built in C++, demonstrating core OOP principles: inheritance, polymorphism, encapsulation, and abstraction.

## Overview

This console application models a simplified traffic challan workflow: registering vehicle owners, registering vehicles, generating violation challans, processing payments, and viewing challan history.

## OOP Design

- **Abstraction & Inheritance:** An abstract `vehicle` base class defines the shared interface (`registervehicle()`, `gettype()`), with `car`, `bike`, `truck`, and `rikshaw` as concrete derived classes.
- **Polymorphism:** Each vehicle subclass overrides `registervehicle()` and `gettype()`, and the `challan` class generates violation details dynamically based on the actual vehicle type at runtime.
- **Encapsulation:** Each class (`owner`, `vehicle`, `payment`, `challan`) manages its own data and behavior, keeping registration, payment, and challan logic cleanly separated.
- **Exception Handling:** Input validation (CNIC length, registration number format, card number length, invalid payment choices) is handled via `try`/`catch` blocks that throw and catch typed exceptions.

## Features

- **Owner registration** with CNIC validation
- **Vehicle registration** across 4 vehicle types (Car, Bike, Truck, Rickshaw), each with its own registration flow
- **Automatic challan generation** — violation type and fine amount are determined based on vehicle type:
  - Car → Seatbelt Violation (Rs. 2000)
  - Bike → No Helmet (Rs. 1000)
  - Truck → Over Speeding (Rs. 2500)
  - Rickshaw → Wrong Turn (Rs. 500)
- **Payment processing** — supports cash or card payment, with card number validation
- **Challan history view** — shows challan status (Paid/Unpaid) and details

## How to Run

Compile and run with any standard C++ compiler:

```bash
g++ "e challan management system code.cpp" -o echallan_oop
./echallan_oop
```

On Windows (MinGW):
```bash
g++ "e challan management system code.cpp" -o echallan_oop.exe
echallan_oop.exe
```

## Tech Stack

- C++ (Object-Oriented Programming: inheritance, polymorphism, encapsulation, abstraction, exception handling)
