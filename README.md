# Hash Tables
The objective of this assignment is to understand the internal operation of Database Management Systems (DBMS) regarding block-level and record-level management, implement a set of functions to manage files created using an extendible hash table (EHT). You will follow an approach that uses the first few bits to build the hash directory.

## Block File Management (BF) Layer
The Block File (BF) Layer functions as a memory manager acting as a cache between the disk and memory. This layer holds disk blocks in memory. When a block is requested, the BF layer first checks if the block is already in memory. If it is, the block is not re-read from the disk. If not, the block is loaded from the disk into memory. Since memory is not infinite, at some point, the BF layer will need to evict a block to make space for another one. The replacement policies you can choose are LRU (Least Recently Used) or MRU (Most Recently Used).

## Extendible Hash Table (EHT) Layer
The Extendible Hash Table (EHT) Layer is responsible for managing the extendible hash table. The goal of this layer is to manage records in a way that utilizes a dynamic directory for efficient lookups.

# Merge Sort

## Overview
This project implements an external sorting algorithm using the merge technique in the context of a Database System, particularly when there is not enough RAM to store the entire heap file. This project focuses on understanding and implementing the external sorting with merging technique and familiarizing students with language processing models, specifically utilizing ChatGPT to assist in the development of executable code.

The algorithm sorts records of a heap file using external memory and simulates the process of merging sorted chunks, iterating through passes until only one sorted chunk remains. Various libraries have been developed to handle heap file operations, sorting, merging, and chunk management.

## Design Choices and Assumptions
External Sorting Algorithm:
The sorting algorithm is implemented as an external sorting method using the merge-sort technique. The heap file is divided into chunks, each of which is sorted independently. Once sorted, the chunks are merged together to form progressively larger sorted chunks until only one chunk remains.


## Compilation:
Use the provided Makefile to compile the project:


