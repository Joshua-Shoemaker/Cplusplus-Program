# Ticking Clock

This project takes an input time and displays two ticking clocks. 
One clock is a 24 hour clock and the second is a 12 hour clock with am and pm markings. 

The initial input is validated to only accept numbers. If the hour input is above 24 hours the clock will roll the hour 
over to a 24 hour format. If the initial hour input is under 12 hours then the clock asks if it is am or pm. 

A menu is displayed allowing the user to add an hour, minute, or second, and quit the program. 

I feel this program utilizes threading effectively to allow a ticking clock while simultaneously listening for user input. 
I found this part of the code most challenging so the user validation messages stay on the screen while the ticking clock 
continues to print. GeeksforGeeks, Stack overflow, and Microsoft Learn were instrumental in learning how to properly implement 
multithreading.

An improvement to this code would be to beutify the output formatting and standardize the console size. This would create a 
more personalized and proffesional application. 

Transferable skills from this project include using best practices and standard naming conventions along with understanding
memory and object management. 

This program is made maintainable, readable, and adaptable through utilizing the principles of OOP. Polymorphism, is expressed 
in the clock class, the class has encapsulated members, and can be manipulated in an abstract manner. 
