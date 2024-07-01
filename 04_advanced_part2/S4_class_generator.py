
def class_generator(class_name):

    # Defining the content for the .h file
    header_file_content = f"""\
#ifndef {class_name.upper()}_H
#define {class_name.upper()}_H

class {class_name} {{
public:
    {class_name}();  // Constructor
    ~{class_name}(); // Destructor
    void display() const;  //method to display the value

private:
    int value;         // Private member variable

}};

#endif // {class_name.upper()}_H
"""

    # Defining the content for the .cpp file
    cpp_file_content = f"""\
#include "{class_name}.h"
#include <iostream>

// Constructor definition
{class_name}::{class_name} {{
    std::cout << "{class_name} is constructed!" << std::endl;
}}

// Destructor definition
{class_name}::~{class_name}() {{
    std::cout << "{class_name} is destructed!" << std::endl;

}}
"""

    # Write the content to the .h file
    with open(f"{class_name}.h", 'w') as header_file:
        header_file.write(header_file_content)

    # Write the content to the .cpp file
    with open(f"{class_name}.cpp", 'w') as cpp_file:
        cpp_file.write(cpp_file_content)

if __name__ == "__main__":
    class_name = input("Please, enter the name of the class: ")
    class_generator(class_name)
    print(f" both {class_name}.h and {class_name}.cpp  files have been created, successfully")