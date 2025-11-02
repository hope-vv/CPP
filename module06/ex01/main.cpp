#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Lina";
    data.score = 99.9;

    std::cout << "Original Data pointer: " << &data << std::endl;

    // Serialize
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    // Deserialize
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << deserialized << std::endl;

    // Check
    if (deserialized == &data)
        std::cout << "Success: Pointers match!" << std::endl;
    else
        std::cout << "Error: Pointers differ!" << std::endl;

    // Print the data values
    std::cout << "ID: " << deserialized->id << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Score: " << deserialized->score << std::endl;

    return 0;
}
