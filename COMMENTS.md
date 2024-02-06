### How should i comment my code?

The following is a **must** if you want to contribute, note that no maintaner or admin will add comments for you, the comments are strictly like this because the documentation is updated from the legacy code.

```cpp
/**
   * @brief some_function function
   * @param X: Explain what X is
   * @param Y: Explain what Y is
   * @returns Type: Explain what the function returns
   */
Type some_function(Type X, Type Y, ...){
    ...
}
```

```cpp
/**
   * @brief struct for aStruct
   * @param a: Explain what a is
   * @param b: Explain what b is
   */
struct aStruct{
    Type a;
    Type b;
    ...
}
```