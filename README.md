# Merge Sort

## Overview
This project implements an external sorting algorithm using the merge technique in the context of a Database System, particularly when there is not enough RAM to store the entire heap file. This project focuses on understanding and implementing the external sorting with merging technique and familiarizing students with language processing models, specifically utilizing ChatGPT to assist in the development of executable code.

The algorithm sorts records of a heap file using external memory and simulates the process of merging sorted chunks, iterating through passes until only one sorted chunk remains. Various libraries have been developed to handle heap file operations, sorting, merging, and chunk management.

## Design Choices and Assumptions
External Sorting Algorithm:
The sorting algorithm is implemented as an external sorting method using the merge-sort technique. The heap file is divided into chunks, each of which is sorted independently. Once sorted, the chunks are merged together to form progressively larger sorted chunks until only one chunk remains.

## Links to ChatGPT Conversations
For each function or structure, the following are the relevant ChatGPT conversations that were used to help design or implement them:

HP_CreateFile function
HP_OpenFile function
sort_FileInChunks function
merge function
CHUNK_CreateIterator function
(Note: The links above should be replaced with the actual URLs of the relevant ChatGPT conversations.)

## Instructions for Compilation and Execution
### Prerequisites:

A Linux environment (GCC 5.4+).
Necessary libraries and headers (bf.h, hp_file.h, etc.).
A properly set up environment as described in the project folder structure.
## Compilation:
Use the provided Makefile to compile the project:


