# CPP_Module_07

## Exercise 00: Start with a few functions

Templates in C++ are a feature that allows functions and classes to operate on generic types. This means you can write a single function or class definition to work with any data type, improving code reusability and flexibility. Templates are defined using the template keyword, followed by template parameters within angle brackets.

```cpp
// Function template for finding the maximum of two values
template <typename T>
T max(T x, T y) {
    return (x > y) ? x : y;
}
```

```cpp
// Class template for a simple Box that can hold any type of item
template <typename T>
class Box {
private:
    T content;
public:
    void setContent(T newContent) {
        content = newContent;
    }
    T getContent() {
        return content;
    }
};

```

## Intra: Videos

### Introduction

Template are awesome!

###

- The syntax of templates
