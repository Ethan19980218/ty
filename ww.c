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