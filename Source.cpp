#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental\filesystem>

#define BUFFER_SIZE_MAX_SIZE 131072

int Write(std::vector<char> cpy_buf, std::fstream& dest) {
	dest.write(cpy_buf.data(), cpy_buf.size() - 1);
	return 0;
}

void copy_utility(std::fstream source, std::fstream dest) {

}

int simple_copy(std::fstream& source, std::fstream& dest) {
	std::copy(
		std::istreambuf_iterator<char>(source),
		std::istreambuf_iterator<char>(),
		std::ostreambuf_iterator<char>(dest));
	return 0;
}


void save_utility(std::string source, std::string dest) {
	
}


int Read(std::vector<char>& cpy_buf, std::fstream& source) {
	source.seekg(0, source.end);
	int length = source.tellg();
	cpy_buf.resize(length);
	source.seekg(0, source.beg);
	source.read(cpy_buf.data(), length);
	return 0;
}

int Open_file(const std::string&& name, std::fstream& source) {
	source.open(name, std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::app);

	if (source.fail()) { // can also use isopen()
		std::cout << "Could not open the file" << std::endl;
		return -1;
	}
	return 0;
}
int close_file(std::fstream& file) {
	file.close();
	return 0;
}

int main() {
	std::fstream input;
	std::fstream output;
	std::vector<char> cpy_buff{};

	if (Open_file("data.txt", input) || Open_file("data_3.txt", output)) {
		printf("failed to open files");
		return -1;
	}

	Read(cpy_buff,input);

	std::cout << cpy_buff.data() << std::endl;

	Write(cpy_buff, output);

	//if (!Open_file("data.txt",input) && !Open_file("data_2.txt", output)) {
	//	printf("Source and destination opened, reading");
	//	simple_copy(input, output);
	//	input.close(); output.close();
	//}
	//else { printf("Unable to open the source or destination file"); return -1; }

	input.close(); output.close();
	return 0;
}