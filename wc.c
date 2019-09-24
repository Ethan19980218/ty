//���������б�
//
//wc.exe - c file.c     //�����ļ� file.c ���ַ���
//
//wc.exe - w file.c    //�����ļ� file.c �Ĵʵ���Ŀ  
//
//wc.exe - l file.c      //�����ļ� file.c ������
//
//
//
//
//��չ���ܣ�
//- s   �ݹ鴦��Ŀ¼�·����������ļ���
//- a   ���ظ����ӵ����ݣ������� / ���� / ע���У���

#include <stdio.h>
int main() { //������
	char input[10], filename[32];
	while (1) {
		
		//����ָ��
		printf("\nwc.exe - c file.c      �����ļ� file.c ���ַ���\nwc.exe - w file.c      �����ļ� file.c �Ĵʵ���Ŀ\nwc.exe - l file.c      �����ļ� file.c ������\nwc.exe - o file.c      �˳�\nwc.exe - a file.c      ���ظ����ӵ����ݣ������� / ���� / ע���У�\n������ָ�- ");
		scanf("%s",&input);
		
		switch(input[0]){
			case 'c':  //�ַ���
				printf("�������ļ�����");//�����ļ���
				scanf("%s", &filename);

				int counts = 0;
				counts = count(filename);
				printf("�ļ����ַ���Ϊ��%d",counts);
				break;
		
			case 'w':  //����				
				printf("�������ļ�����");//�����ļ���
				scanf("%s", &filename);

				int words = 0;
				words = word(filename);
				printf("�ļ��Ĵ���Ϊ��%d", words);
				break;

			case 'l':  //����
				printf("�������ļ�����");//�����ļ���
				scanf("%s", &filename);

				int lines = 0;
				lines = line(filename);
				printf("�ļ�������Ϊ��%d", lines+1);
				break;

			case 'a':	//���ظ����ӵ����ݣ������� / ���� / ע���У���
				printf("�������ļ�����");//�����ļ���
				scanf("%s", &filename);
				data(filename);
				break;

			case 's': //�ݹ鴦��Ŀ¼�·����������ļ�
				if (input[3] == 'a') {
				
				}
				break;
		
			case 'o':  //�˳�
				return 0;

			default:
				printf("�������ָ����������������");
				break;
		}

	}
	system("pause");
	return 0;

}

int count(char filename[]) { //�����ļ��ַ���
	FILE *f = NULL;
	f = fopen(filename,"r");
	if (f == NULL) {
		printf("�޷��ҵ����ļ���");
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

int word(char filename[]){ //�����ļ��ʵ���Ŀ
	FILE *f = NULL;
	f = fopen(filename, "r");
	if (f == NULL) {
		printf("�޷��ҵ����ļ���");
		exit(-1);
	}

	char fchar = 0;
	int count = 0;
	fchar = fgetc(f);
	while (fchar != EOF)
	{
		if ((fchar >= 'a' && fchar <= 'z') || (fchar >= 'A' && fchar <= 'Z') )//������ĸ
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

int line(char filename[]) { //�����ļ�����
	FILE *f = NULL;
	f = fopen(filename, "r");
	if (f == NULL) {
		printf("�޷��ҵ����ļ���");
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

int data(char filename[]) {  //��չ
	FILE *f = NULL;
	f = fopen(filename, "r");
	if (f == NULL) {
		printf("�޷��ҵ����ļ���");
		exit(-1);
	}

	char fchar = 0;
	int line = 0, code = 0, note = 0;
	int l = 0, n = 0, c = 0;//lΪ�������ͣ�0�����ַ����У�1��1�ַ����У�nΪע�����ͣ�0Ϊ��ע���У�1Ϊ��ע���У�2Ϊ��ע����,cΪ��������

	while (fchar != EOF) {
		fchar = fgetc(f);
			if (l == 0 || l == 1) {//�����ʼ�ǿո���Ʊ���ʼ�ж��ǲ��ǿ��л���ע���л��ߴ�����
				if (fchar == '\n') {//�س�֮ǰû���ַ�������;1�ַ������Ҳ��û�������ַ�
					line++;
					l = 0;
					continue;
				}
				else if (fchar == '/') {//ע���ж�
					fchar = fgetc(f);
					if (fchar == '/') {//����ע��
						n = 1;
						while (fchar != EOF && fchar != '\n') {
							fchar = fgetc(f);
						}
						n = 0;
						note++;
						continue;
					}
					else if (fchar == '*') {//����ע��
						n = 2;
						continue;
					}
				}
				else if( fchar == '}' && l == 0){
					l = 1;		//һ�ַ�����
					continue;
				}
				else if(fchar == ' ' || fchar == '\t'){
					continue;
				}
				else {
					c = 1;
				}
			}
			if (c == 1) {//������
				while (fchar != EOF && fchar != '\n') {
					fchar = fgetc(f);
				}
				l = 0;//״̬��ؿ���
				code++;
				continue;
			}
			if (n == 2) {//����ע��
				while (fchar != EOF && fchar != '*') {
					while (fchar != EOF && fchar != '\n') {
						fchar = fgetc(f);
					}
					note++;
					fchar = fgetc(f);
				}
				fchar = fgetc(f);
				if (fchar == '/') {//���н���
					n = 0;
				}
				continue;
			}
	}
	printf("\n���п�����: %d  \n��������: %d  \nע������: %d\n", line, code, note);
	fclose(f);
}
