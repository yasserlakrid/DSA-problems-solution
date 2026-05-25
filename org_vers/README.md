# Data Structures Libraries - org_vers

Complete collection of well-organized, production-ready C libraries for fundamental data structures.

## 📦 Libraries

### 1. **Arrays** (`Arrays/`)
Dynamic array implementation with automatic resizing
- **Header:** `array.h`
- **Implementation:** `array.c`
- **Key Features:** 
  - Automatic capacity management
  - Insertion, deletion, searching
  - Sorting and reversal
  - Display functions

### 2. **Linked Lists** (`linkedList/`)
Single linked list with full traversal support
- **Header:** `linkedList.h`
- **Implementation:** `linkedList.c`
- **Key Features:**
  - Front/end/index insertion
  - Forward traversal
  - Reversal and sorting
  - Size tracking

### 3. **Doubly Linked Lists** (`DoublyList/`)
Bidirectional linked list for efficient access
- **Header:** `doublyList.h`
- **Implementation:** `doublyList.c`
- **Key Features:**
  - Bidirectional traversal
  - Optimized element access
  - No predecessor search needed
  - Forward and backward display

### 4. **Stacks** (`Stacks/`)
LIFO (Last-In-First-Out) data structure
- **Header:** `stack.h`
- **Implementation:** `stack.c`
- **Key Features:**
  - Push/Pop operations
  - Peek functionality
  - Size and empty checks
  - Display from top

### 5. **Queues** (`Queues/`)
FIFO (First-In-First-Out) data structure
- **Header:** `queue.h`
- **Implementation:** `queue.c`
- **Key Features:**
  - Enqueue/Dequeue operations
  - Front/Rear peek
  - Size and empty checks
  - Display front to rear

### 6. **Binary Search Trees** (`Trees/`)
Sorted binary tree with multiple traversals
- **Header:** `tree.h`
- **Implementation:** `tree.c`
- **Key Features:**
  - Insertion and deletion
  - Multiple traversal methods (Inorder, Preorder, Postorder, Levelorder)
  - Min/Max finding
  - Height calculation

## 📋 Folder Structure

```
org_vers/
├── Arrays/
│   ├── array.h
│   ├── array.c
│   └── README.md
├── linkedList/
│   ├── linkedList.h
│   ├── linkedList.c
│   └── README.md
├── DoublyList/
│   ├── doublyList.h
│   ├── doublyList.c
│   └── README.md
├── Stacks/
│   ├── stack.h
│   ├── stack.c
│   └── README.md
├── Queues/
│   ├── queue.h
│   ├── queue.c
│   └── README.md
└── Trees/
    ├── tree.h
    ├── tree.c
    └── README.md
```

## 🎯 API Conventions

All libraries follow consistent naming conventions:

### Naming Pattern
- `structure_operation()` format
- Examples: `array_append()`, `linkedlist_insert_end()`, `stack_push()`

### Memory Management
- `type_create()` - Initialize and allocate
- `type_free()` - Deallocate all memory

### Core Operations
- Insert/Add/Push/Enqueue - Add elements
- Remove/Delete/Pop/Dequeue - Remove elements
- Get/Find/Peek - Access elements without modification

### Utilities
- `type_is_empty()` - Check if empty
- `type_size()` - Get element count
- `type_clear()` - Remove all elements

### Display Functions
- `type_display()` - Print structure contents
- May have multiple display methods (forward, backward, etc.)

## 💡 Time Complexity Reference

| Operation | Array | LinkedList | Stack | Queue | Tree |
|-----------|-------|-----------|-------|-------|------|
| Access    | O(1)  | O(n)      | -     | -     | O(log n) |
| Search    | O(n)  | O(n)      | O(n)  | O(n)  | O(log n) |
| Insert    | O(n)  | O(1)*     | O(1)  | O(1)  | O(log n) |
| Delete    | O(n)  | O(1)*     | O(1)  | O(1)  | O(log n) |

*With pointer to location

## 🚀 Quick Example

```c
#include "array.h"

int main() {
    // Create
    Array *arr = array_create(10);
    
    // Add elements
    array_append(arr, 5);
    array_append(arr, 3);
    array_append(arr, 8);
    
    // Display
    array_display(arr);  // [5, 3, 8]
    
    // Sort
    array_sort(arr);
    array_display(arr);  // [3, 5, 8]
    
    // Clean up
    array_free(arr);
    return 0;
}
```

## 📖 Documentation

Each library includes:
- Complete function reference
- Structure definitions
- Time complexity analysis
- Usage examples
- Common applications

See individual `README.md` files in each library folder for detailed documentation.

## ✨ Features

✅ Memory safe with proper allocation/deallocation
✅ Comprehensive error checking
✅ Consistent and intuitive API
✅ Well-documented with examples
✅ Production-ready code quality
✅ Modular and independent libraries

---

**All libraries follow standard C conventions and best practices for data structure implementation.**
