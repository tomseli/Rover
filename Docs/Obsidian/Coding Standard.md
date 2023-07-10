# Comments
1. Code shall never be commented out, even temporarily. 
	1. To temporarily disable a block a pre-processor shall be used (eg. `#if 0` and `#endif`).
2. Functions will always have a Doxygen like comment before it using the following style
```c
/* 
 * @brief This function does something
 * @param name [type] This parameter does something
*/
```

# Naming Convention
```
Macros, defines and constants  ALL_CAPS

Struct names and typedefs      PascalCase
Struct members                 camelCase

Local variables                snake_case

Functions                      ModulePascalCase
```
1. Place the * close the the pointer type eg `char* name = NULL;`

# Formatting
The brace placement strategy is recommended
Avoid one-liners, unless the ternary operator is used.
```c
if(conditon == 1)
{

}

switch(variable)
{
	case 1:
		DoSomething()
		break;
	case 2:
		DoSomethingElse()
		break;
}
```