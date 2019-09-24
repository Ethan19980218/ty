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

int count(char filename[]) { //返回文件字符数
	FILE *f = NULL;
	f = fopen(filename,"r");
	if (f == NULL) {
		printf("无法找到此文件！");
		exit(-1);
	}

	char fchar = 0;
	int count = 0;
	fchar = fgetc(f);
	for(count = 0; fchar != EOF; count++){
		fchar = fgetc(f);
	}
	fclose(f);
	return count;
}

int word(char filename[]){ //返回文件词的数目
	FILE *f = NULL;
	f = fopen(filename, "r");
	if (f == NULL) {
		printf("无法找到此文件！");
		exit(-1);
	}

	char fchar = 0;
	int count = 0;
	fchar = fgetc(f);
	while (fchar != EOF)
	{
		if ((fchar >= 'a' && fchar <= 'z') || (fchar >= 'A' && fchar <= 'Z') )//遇到字母
		{
			while ((fchar >= 'a' && fchar <= 'z') || (fchar >= 'A' && fchar <= 'Z'))
				fchar = fgetc(f);
			count++;
			fchar = fgetc(f);
		}
		else {
			fchar = fgetc(f);
		}
	}
	fclose(f);
	return count;
}

int line(char filename[]) { //返回文件行数
	FILE *f = NULL;
	f = fopen(filename, "r");
	if (f == NULL) {
		printf("无法找到此文件！");
		exit(-1);
	}

	char fchar = 0;
	int count = 0;

	fchar = fgetc(f);
	for (count = 0; fchar != EOF; fchar = fgetc(f)) {
		if (fchar == '\n') {
			count++;
		}
	}
	fclose(f);
	return count;
}

int data(char filename[]) {  //拓展
	FILE *f = NULL;
	f = fopen(filename, "r");
	if (f == NULL) {
		printf("无法找到此文件！");
		exit(-1);
	}

	char fchar = 0;
	int line = 0, code = 0, note = 0;
	int l = 0, n = 0, c = 0;//l为空行类型，0是无字符空行，1是1字符空行；n为注释类型，0为非注释行，1为单注释行，2为多注释行,c为代码类型

	while (fchar != EOF) {
		fchar = fgetc(f);
			if (l == 0 || l == 1) {//如果开始是空格或制表，开始判断是不是空行或者注释行或者代码行
				if (fchar == '\n') {//回车之前没有字符，空行;1字符进入后也是没有其他字符
					line++;
					l = 0;
					continue;
				}
				else if (fchar == '/') {//注释判断
					fchar = fgetc(f);
					if (fchar == '/') {//单行注释
						n = 1;
						while (fchar != EOF && fchar != '\n') {
							fchar = fgetc(f);
						}
						n = 0;
						note++;
						continue;
					}
					else if (fchar == '*') {//多行注释
						n = 2;
						continue;
					}
				}
				else if( fchar == '}' && l == 0){
					l = 1;		//一字符空行
					continue;
				}
				else if(fchar == ' ' || fchar == '\t'){
					continue;
				}
				else {
					c = 1;
				}
			}
			if (c == 1) {//代码行
				while (fchar != EOF && fchar != '\n') {
					fchar = fgetc(f);
				}
				l = 0;//状态变回空行
				code++;
				continue;
			}
			if (n == 2) {//多行注释
				while (fchar != EOF && fchar != '*') {
					while (fchar != EOF && fchar != '\n') {
						fchar = fgetc(f);
					}
					note++;
					fchar = fgetc(f);
				}
				fchar = fgetc(f);
				if (fchar == '/') {//多行结束
					n = 0;
				}
				continue;
			}
	}
	printf("\n共有空行数: %d  \n代码行数: %d  \n注释行数: %d\n", line, code, note);
	fclose(f);
}
