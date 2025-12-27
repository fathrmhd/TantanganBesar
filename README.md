# Text Data Processing in C

This project is a C-based text processing program designed to analyze textual data from a `.txt` file, extract meaningful words, count their frequencies, and sort them based on predefined rules.

The program focuses on processing words contained inside specific sections of the text (`<title>` and `<body>`), while ignoring irrelevant parts such as URLs and non-alphabetic characters.

---

## Features

- Read text input from a file
- Extract words only from `<title>` and `<body>` sections
- Ignore URLs and non-alphabetic characters
- Convert all words to lowercase
- Count frequency of unique words
- Sort words based on:
  1. Highest frequency
  2. Longest word length (if frequencies are equal)
  3. Alphabetical order (if both are equal)
- Save processed data into a binary file
- Display top `n` most frequent words per alphabet group

---

## Project Structure

├── main.c
├── listFunction.c
├── header.h
├── hasil.bin
└── README.md


---

## Data Structure

```c
typedef struct {
    char kata[maxPanjang];
    int panjang;
    int frekuensi;
} DataKata;

This structure stores:

    kata : the word

    panjang : word length

    frekuensi : number of occurrences

Program Workflow

    User inputs the name of a text file

    The program reads the file line by line

    Words are extracted only from <title> and <body> tags

    Each word is cleaned and normalized

    Word frequency is calculated and stored

    All words are sorted based on defined criteria

    Results can be saved to a binary file and displayed on screen

Function Overview
cleanSafe()

Cleans input words by:

    Removing non-alphabetic characters

    Converting letters to lowercase

    Updating word frequency if it already exists

    Adding new words to the database if not found

bukaFile()

    Opens and reads the input text file

    Tokenizes text using delimiters

    Ignores URL sections and links

    Sends valid words to cleanSafe() for processing

urutkanData()

    Sorts all collected words using bubble sort

    Applies multi-level comparison:
    frequency → length → alphabetical order

simpanBinary() & tampilkanData()

    Handle binary file storage and output display

    Group words based on starting alphabet

    Display top n words per group

Compilation & Execution

gcc main.c listFunction.c -o text_processor
./text_processor

Notes

    Maximum number of unique words: 200000

    Maximum word length: 100

    Input file must be a .txt file

    Program is case-insensitive

Author

Muhammad Fathir
Computer Science Student
Universitas Syiah Kuala
License

This project is intended for academic and educational purposes.


---
