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

Left-leaning Red-Black trees are a self-balancing binary search tree data structure that maintains order and ensures logarithmic height for efficient search, insertion, and deletion operations of O(log n). These trees are an extension of traditional Red-Black Binary Search Trees with an additional property called "left-leaning," which simplifies the implementation of rotations. In an LLRBtree, each node is labeled with a color (red or black) and a key value. The tree adheres to the standard Red-Black properties as so. Firstly, every node is colored either red or black. Next, the root node and null descendant leaves are always black. Furthermore, if a node is red, then both its children are black. Lastly, every path from a node to its descendant leaves contains the same number of black nodes.
The difference between a red-black tree and a LLRB is this addition of the “left-leaning” property. This is used to simplify the coloring and balancing of the tree. This property of left-leaning means that red nodes can only exist on the left-hand pointer of a node. This simplifies the process of delegating whether a node is red or black, and simplifyies the tree's structure and rotation algorithms. This left-leaning characteristic streamlines the implementation of rotations during insertions and deletions, making the LLRB tree an efficient choice for maintaining a balanced binary search tree.
A “rotation” needs to be performed in the tree when the tree needs to be restructured to maintain its LLRB properties. Rotations can be of two types: left rotations and right rotations. A left rotation is used when a right-leaning red link is encountered in the tree, and it involves rearranging the nodes to shift the imbalance. On the other hand, a right rotation is applied when a black node has two red children. During a left rotation, the parent node becomes the new parent of the current node’s right child. Then the right child pointer becomes the new parent’s left child. Finally, the left child of the right child becomes the right child of the current node. Similarly, for a right rotation, the same thing occurs, except it is mirrored.


## Implementation

Our Community Library program utilizes our data structure, left-leaning red-black tree, to store all of our books in a library. For the sake of our project, we created a new LLRB Tree class variant called “BookTree.” Just like any other BST, we created a “BookTreeNode” class as well. Finally, we created one more class, called “Book.” This Book class is responsible for storing the key information of each individual book instance– such as the book's title, author, non-fiction/fiction, genre, type, and page length. Additionally, the “Book” class also contains a member variable “serial,” which is not inputted into the object directly. Instead, the constructor will use the other given information to create the serial number. This serial number is a core concept in our BookTree, since it acts as the key for each node. As opposed to a standard LLRB-tree, which simply only contains integer values, our BookTreeNodes contain all of the listed member variables. When the BookTreeNodes are being inserted into the BookTree, it compares the node’s serial number with other serial numbers to place it in.
Upon running the code, the program takes in a file called library.txt, which contains the necessary information for each individual book, separated by line. The Community Library program will create a Book instance for each line, and consequently a BookTreeNode containing it. As the stream reads in the books, it will be inserted into our newly created BookTree. While this process is happening, the serial number for each book is being created in real-time.
In order to create this four-digit serial number, the constructor considers the information of the book. The first digit determines whether the book is Non-fiction/Fiction, represented by a 1 or 2. The second digit represents the genre (Mystery, Science, Fantasy, Romance, History, Dystopian, Comedy, Horror, Biography, Adventure, 0-9), and the third digit represents the type of text (Novel, Textbook, Poetry, Essay, Short Story). The fourth and final digit of the serial number represents the length of the book in increments of 100 (For example, 365 pages would fall under the ‘3’ category). So, at the end of this serial creation, we will have a 4-digit number that represents the specific book.
To give an example of this creation, let’s say we have the book “Harry Potter & The Sorcerer’s Stone.” We start off the serial number by initializing it to zero. Then, since it is fiction, we perform the operation “serial += 1000;”. This ensures that the first digit is a 1. Then we add 200, 00, and 3, respectively because it is fantasy, novel, and 320 pages long. This serial number is crucial in the implementation of our program, since it is the “key” for our LLRB tree’s nodes. Without the serial number, we wouldn’t have any data values to compare nodes to each other within the tree.
	The Community Library features two core functionalities—insertion and search (or in our case, suggestion). When the program is run, the user is prompted which function they would like to use. For the sake of simplicity, let’s assume that the user just finished reading a great book, and they want to add it to the library for others to discover. First, the program will ask the user to type in the title of the book, followed by author, non/fiction, etc. Once this is completed, an instance of this new book will be created and inserted into the BookTree. Now, the program will return to the original greeting message, with the updated tree. Once the user decides to terminate the program, it will also update the library.txt file.

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

## Other Notes
We have added a few files to help visualize what a left-leaning red-black tree would look like using the file "presentation.dot". This file is the dot file which creates the dot graph called "presentation.png". This tree was derived from the "presentation.txt" file. This file is what you would run with our program and the "presentation.txt" is the visualization of the tree that our program makes. The file "presentations_with_serial.txt" is the file which shows which books with the corresponding serial number. This is very important to understand which book is represented by the serial numbers in "presentation.txt".

## Conclusion

In conclusion, our project successfully implemented the left-leaning red-black tree (LLRB tree) data structure to create an efficient and user-friendly Community Library. The LLRB tree's balanced nature ensures quick access to book information, making our application a reliable and robust platform for book enthusiasts. The use of LLRB trees in our library provides a solid foundation for future expansions and improvements, demonstrating the effectiveness of this data structure in real-world applications.`
