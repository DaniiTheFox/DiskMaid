#include <iostream>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <cstdint>

namespace fs = std::filesystem;

int chsize(std::string _name, int _dsize);

int main(){
 std::cout<<"  ____  _     _    __  __       _     _         "<<std::endl;
 std::cout<<" |  _ \\(_)___| | _|  \\/  | __ _(_) __| |  ______"<<std::endl;
 std::cout<<" | | | | / __| |/ / |\\/| |/ _` | |/ _` | | |__| |"<<std::endl;
 std::cout<<" | |_| | \\__ \\   <| |  | | (_| | | (_| | |  ()  |"<<std::endl;
 std::cout<<" |____/|_|___\/_|\\_\\_|  |_|\\__,_|_|\\__,_| |______|"<<std::endl;
 std::cout<<"----------------------------------------"<<std::endl;
 fs::space_info _space = fs::space("/home/");
 std::cout<<"Free space: "<<_space.free<<"\n"
	  <<"disk size: "<<_space.available<<std::endl;
 std::uintmax_t Dsize = _space.available;
 std::cout<<"cleaning: "<<Dsize<<std::endl;
 std::cout<<"NOTICE: this script will create a huge file"<<std::endl;
 std::ofstream f_dump;
 f_dump.open("brush", std::ios::out);
 std::uintmax_t limit = 0;
 while(limit < Dsize){
	system("objdump -d ./DiskMaid > 0x23423452.t");
	system("rm 0x23423452.t");
	f_dump << "0" << std::endl;
	limit++;
 }
 f_dump.close();
 //close(fd);
 std::cout<<"doing a small cleanup..."<<std::endl;
 system("ls -la");
 system("rm brush");
 std::cout<<"script ended successfully :D"<<std::endl;
 return 0;
}
