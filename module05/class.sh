#!/bin/bash

folders=("ex00" "ex01" "ex02" "ex03")

capitalize() {
	echo "$1" | awk '{print toupper(substr($0,1,1)) substr($0,2)}'
}

for folder in "${folders[@]}"; do
	read -p "Enter class name for $folder: " className
	ClassName=$(capitalize "$className")

	hpp_file="$folder/sources/$ClassName.hpp"
	cpp_file="$folder/sources/$ClassName.cpp"
	include_guard="$(echo "$ClassName" | tr '[:lower:]' '[:upper:]')_HPP"

	# Create .hpp file
	cat > "$hpp_file" << EOF
#ifndef $include_guard
#define $include_guard

#include <iostream>
#include <string>

class $ClassName
{
	protected:

	private:

	public:
		$ClassName();
		~$ClassName();
		$ClassName(const $ClassName &other);
		$ClassName &operator=(const $ClassName &other);
};

#endif
EOF

	# Create .cpp file
	cat > "$cpp_file" << EOF
#include "$ClassName.hpp"

$ClassName::$ClassName()
{
	std::cout << "$ClassName default constructor called" << std::endl;
}

$ClassName::~$ClassName()
{
	std::cout << "$ClassName destructor called" << std::endl;
}

$ClassName::$ClassName(const $ClassName &other)
{
	std::cout << "$ClassName copy constructor called" << std::endl;
	*this = other;
}

$ClassName &$ClassName::operator=(const $ClassName &other)
{
	std::cout << "$ClassName copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// Copy members here
	}
	return *this;
}
EOF

	echo "✅ Created $hpp_file and $cpp_file"
done
