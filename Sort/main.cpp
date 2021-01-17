#include"Header.h"
void main()
{
	char x;
	ofstream F;
	F.open("Results.csv", ios::app);
	if (F)
	{
		F << "Case" << "," << "Size" << "," << "Bubble" << "," << "Slection" << "," << "Insertion" << "," << "Heap" << "," << "Quick" << "," << "Merge" << "," << "BinaryInsertion\n";
	}
	F.close();
MENU:
	{
		system("cls");
		cout << "\t\t\t\tNHAP LUA CHON";
		cout << "\n\n\t\t\t1.PHAT SINH MANG NGAU NHIEN";
		cout << "\n\n\t\t\t2.PHAT SINH MANG CO THU TU TANG DAN";
		cout << "\n\n\t\t\t3.PHAT SINH MANG NGUOC";
		cout << "\n\n\t\t\t4.PHAT SINH MANG GAN NHU CO THU TU";
		cout << "\n\n\nLua chon cua ban: ";
		int chon;
		cin >> chon;
		switch (chon)
		{
		case 1:
			Random();
			cout << "Sap xep  da xong\n";
			cout << "nhap 'T' de quay lai menu hoac phim bat ki de thoat \n";
			fflush(stdin);
			cin >> x;
			if (x == 'x' || x == 'X')
			{
				goto MENU;
			}
			break;
		case 2:
			Sorted();
			cout << "Sap xep  da xong\n";
			cout << "nhap 'T' de quay lai menu hoac phim bat ki de thoat  \n";
			fflush(stdin);
			cin >> x;
			if (x == 'x' || x == 'X')
			{
				goto MENU;
			}
			break;
		case 3:
			Reverse();
			cout << "Sap xep  da xong\n";
			cout << "nhap 'T' de quay lai menu hoac phim bat ki de thoat  \n";
			fflush(stdin);
			cin >> x;
			if (x == 'x' || x == 'X')
			{
				goto MENU;
			}
			break;
		case 4:
			NearlySorted();
			cout << "Sap xep da xong\n";
			cout << "nhap 'T' de quay lai menu hoac phim bat ki de thoat \n";
			fflush(stdin);
			cin >> x;
			if (x == 'x' || x == 'X')
			{
				goto MENU;
			}
			break;
		default:
			cout << "GOOD BYE";
		}
	}
	_getch();

}