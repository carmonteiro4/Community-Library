`# Left-leaning red-black BSTs: Community Library

**Authors:** Carlos Monteiro, Kasem Sasa, James Furtado, William Tsafack  
**Affiliation:** The University of Rhode Island  
**Course:** CSC 212 - Data Structures & Abstractions  
**Professor:** Professor Schrader  
**Date:** 5 December 2023

## Table of Contents

1. [Topic Introduction](#topic-introduction)
    - Context & Purpose
    - Surface Level Detail
2. [Project Introduction](#project-introduction)
    - What is it
    - Why did you Choose it
    - How does it Mesh with your Topic
3. [Methods](#methods)
    - Explain the Data Structure / Algorithm in Depth
        - Deeper Thinking Details
4. [Implementation](#implementation)
    - Describes our Work
    - Highlights Portions of Code to Address
    - Includes Input Scenarios, Actual Output from the Code
5. [Dependencies-and-Instructions](#Dependencies-and-Instructions)
    - Explains Dependencies
    - Explains Compiler Instructions
6. [Contributions](#contributions)
    - A table with each member's contributions
7. [Conclusion](#conclusion)
    - Findings from research
    - Findings from programming

## Topic Introduction

Red-Black Trees are a fundamental data structure, first introduced by Guibas and Sedgewick approximately three decades ago. In the realm of search tree structures, the red-black tree model has become a fundamental component in computer programming because of its simple implementation and efficiency. However, over time, many implementations have deviated from the original design goals, particularly in pursuit of an effective delete operation. In response to this, a new variant emerged—left-leaning red-black trees (LLRB trees).

LLRB trees aim to revive the core design objectives of red-black trees and simplify the code for insert and delete operations, offering a more elegant and efficient solution. With LLRB trees providing a consistent time complexity of O(log n) and a simple implementation, the data structure has proven itself as a viable and effective competitor amongst other structures.

## Project Introduction

For this project, we designed an application called "Community Library." This library acts as a database for a wide variety of books, which users can add to or search for new reads. Our primary objective was to leverage the efficient time complexity of LLRB trees within our own functions, creating a seamless and quick user interaction. The user interface is designed to guide individuals through the process of discovering new books or contributing their own books to the database. With LLRB trees providing a consistent time complexity of O(log n) and a simple implementation, the data structure has proven itself as a viable and effective competitor amongst other structures.

## Methods

We implemented the left-leaning red-black tree (LLRB tree) data structure to store and manage the books in our Community Library. The LLRB tree allows for efficient data retrieval with a search time of O(log(n)). The unique serial numbers generated for each book based on its attributes serve as the key for the LLRB tree's nodes. Our implementation includes the insertion and search (suggestion) functionalities.

## Implementation

Our Community Library program utilizes the LLRB tree to store all books. The program reads data from a text file containing book information, creating a unique object for each book. The LLRB tree ensures fast data retrieval due to its balanced nature. The program features two core functionalities—insertion and book suggestion.

To give an example of serial number creation, if we have the book "Harry Potter & The Sorcerer’s Stone" which is fiction, fantasy, a novel, and 320 pages long, the serial number would be 1320.

## Dependencies-and-Instructions

#### Dependencies

- C++ compiler (e.g., g++)
- Must have all files in repository downloaded to one folder
- Must have a compiler that can access -std=c++17

#### Instructions

- Command to compile : g++ -std=c++17 main.cpp BookTree.cpp Book.cpp -o CommunityLibrary
- Execution command  : ./CommunityLibrary library.txt

## Contributions

| Name            | Contribution                                                                                                                                                                                                                          |
| --------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Kasem Sasa      | - Developed project idea<br/>- Created Book.h and Book.cpp files<br/>- Tested Book.h and Book.cpp files<br/>- Fully developed the Book Class<br/>- Aided in the creation and testing of main functionality and BookTree functions<br/>- Developed the insert function<br/>- Coded the suggester function<br/>- Documented the implementation of the project in the report<br/>- Created DOT file for visualization |
| William Tsafack | - Developed project idea<br/>- Created Readme file<br/>- Developed the layout and infrastructure of the readme file<br/>- Aided in the creation and implementation of the user interface<br/>- Organized the design and implementation of the presentation |
| Carlos Monteiro | - Developed project idea<br/>- Created the GitHub Repository<br/>- Created main.cpp file<br/>- Tested main.cpp file<br/>- Built user interface and working main file with conditionals<br/>- Developed a way to generate serial numbers for books<br/>- Built a library file to receive and test data<br/>- Documented the information required and setup to develop code in the report<br/>- Created and designed project presentation |
| James Furtado   | - Developed project idea<br/>- Developed the infrastructure of the GitHub Repository<br/>- Created BookTree.h and BookTree.cpp files<br/>- Tested BookTree.h and BookTree.cpp files<br/>- Fully developed the BookTree class<br/>- Aided in the creation and testing of main functionality and Book functions<br/>- Developed the search function<br/>- Documented the implementation of the project in the report |

## Conclusion

In conclusion, our project successfully implemented the left-leaning red-black tree (LLRB tree) data structure to create an efficient and user-friendly Community Library. The LLRB tree's balanced nature ensures quick access to book information, making our application a reliable and robust platform for book enthusiasts. The use of LLRB trees in our library provides a solid foundation for future expansions and improvements, demonstrating the effectiveness of this data structure in real-world applications.`