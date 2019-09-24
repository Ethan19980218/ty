//基本功能列表：
//
//wc.exe - c file.c     //返回文件 file.c 的字符数
//
//wc.exe - w file.c    //返回文件 file.c 的词的数目  
//
//wc.exe - l file.c      //返回文件 file.c 的行数
//
//
//
//
//扩展功能：
//- s   递归处理目录下符合条件的文件。
//- a   返回更复杂的数据（代码行 / 空行 / 注释行）。

#include <stdio.h>
int main() { //主函数
	char input[10], filename[32];
	while (1) {
		
		//输入指令
		printf("\nwc.exe - c file.c      返回文件 file.c 的字符数\nwc.exe - w file.c      返回文件 file.c 的词的数目\nwc.exe - l file.c      返回文件 file.c 的行数\nwc.exe - o file.c      退出\nwc.exe - a file.c      返回更复杂的数据（代码行 / 空行 / 注释行）\n请输入指令：- ");
		scanf("%s",&input);
		
		switch(input[0]){
			case 'c':  //字符数
				printf("请输入文件名：");//输入文件名
				scanf("%s", &filename);

				int counts = 0;
				counts = count(filename);
				printf("文件的字符数为：%d",counts);
				break;
		
			case 'w':  //词数				
				printf("请输入文件名：");//输入文件名
				scanf("%s", &filename);

				int words = 0;
				words = word(filename);
				printf("文件的词数为：%d", words);
				break;

			case 'l':  //行数
				printf("请输入文件名：");//输入文件名
				scanf("%s", &filename);

				int lines = 0;
				lines = line(filename);
				printf("文件的行数为：%d", lines+1);
				break;

			case 'a':	//返回更复杂的数据（代码行 / 空行 / 注释行）。
				printf("请输入文件名：");//输入文件名
				scanf("%s", &filename);
				data(filename);
				break;

			case 's': //递归处理目录下符合条件的文件
				if (input[3] == 'a') {
				
				}
				break;
		
			case 'o':  //退出
				return 0;

			default:
				printf("你输入的指令有误！请重新输入");
				break;
		}

	}
	system("pause");
	return 0;

}