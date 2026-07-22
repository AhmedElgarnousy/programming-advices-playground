#include <iostream>
#include <fstream>
#include "pugixml.hpp"

int main()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("example.xml");

    if (!result)
    {
        std::cerr << "load error: " << result.description() << "at offset " << result.offset << "\n";
        return 1;
    }

    std::cout << "Loaded Ok. Mesh name: "
              << doc.child("mesh").attribute("name").value() << "\n";

    pugi::xml_node tools = doc.child("mesh").child("tools");

    // Range-based for loop (C++11)
    for (pugi::xml_node tool : tools.children("Tool"))
    {
        std::cout << "Tool " << tool.attribute("Filename").value();
        std::cout << ": AllowRemote=" << tool.attribute("AllowRemote").as_bool();
        std::cout << ", Timeout=" << tool.attribute("Timeout").as_int();
        std::cout << ", Desc='" << tool.child_value("Description") << "'\n";
    }

    return 0;
}
