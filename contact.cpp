#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct contact {
    char name[50];
    char sdt[11];
    char email[30];
} Contact;

Contact c[2000];
int dem = 0;

void proper(char s[]) {
    int len = strlen(s);
    if (len > 0) {
        s[0] = toupper(s[0]);
        for (int i = 1; i < len; i++) {
            if (s[i - 1] == ' ' && s[i] != '\0')
                s[i] = toupper(s[i]);
            else
                s[i] = tolower(s[i]);
        }
    }
    printf("%20s", s);
}

void nhapContact() {
    printf("Nhap so luong danh ba: ");
    scanf("%d", &dem);
    getchar(); 

    for (int i = 0; i < dem; i++) {
        printf("Nhap thong tin lien he thu %d:\n", i + 1);

        printf("Ho va ten: ");
        fgets(c[i].name, 50, stdin);
        c[i].name[strcspn(c[i].name, "\n")] = 0; 

        printf("So dien thoai: ");
        fgets(c[i].sdt, 11, stdin);
        c[i].sdt[strcspn(c[i].sdt, "\n")] = 0;

        printf("Email: ");
        fgets(c[i].email, 30, stdin);
        c[i].email[strcspn(c[i].email, "\n")] = 0;
    }
}

void hienThiContact() {
    printf("\nDANH BA LIEN HE:\n");
    for (int i = 0; i < dem; i++) {
        proper(c[i].name);
        proper(c[i].sdt);
        proper(c[i].email);
        printf("\n");
    }
}

void find() {
    char nameFind[50];
    char sdtFind[11];
    char emailFind[30];
    printf("Ho va ten de tim: ");
    fgets(nameFind, 50, stdin);
    nameFind[strcspn(nameFind, "\n")] = 0; // Xóa ký t? xu?ng dòng
    printf("So dien thoai de tim: ");
    fgets(sdtFind, 11, stdin);
    sdtFind[strcspn(sdtFind, "\n")] = 0;
    printf("Email de tim: ");
    fgets(emailFind, 30, stdin);
    emailFind[strcspn(emailFind, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < dem; i++) {
        if (strcmp(c[i].name, nameFind) == 0 && strcmp(c[i].sdt, sdtFind) == 0 && strcmp(c[i].email, emailFind) == 0) {
            printf("Tim thay contact thu %d:\n", i + 1);
            printf("Ho va ten: %s\n", c[i].name);
            printf("So dien thoai: %s\n", c[i].sdt);
            printf("Email: %s\n", c[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact khong tim thay\n");
    }
}
void delContact() {
    int indexDel = 0;
    printf("Ban muon xoa contact thu may? ");
    scanf("%d", &indexDel);

    if (indexDel < 1 || indexDel > dem) {
        printf("Khong co contact thu %d!\n", indexDel);
        return;
    }

    for (int i = indexDel - 1; i < dem - 1; i++) {
        c[i] = c[i + 1];
    }
    dem--;

    printf("Da xoa contact thu %d thanh cong!\n", indexDel);
}

void printAsc(Contact *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(a[j].name, a[j + 1].name) > 0) {
                Contact temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nDANH BA LIEN HE (SAP XEP THEO TEN):\n");
    for (int i = 0; i < n; i++) {
        proper(c[i].name);
        proper(c[i].sdt);
        proper(c[i].email);
        printf("\n");
    }
}

int main() {
	int choice = 1;
	while(choice){
		printf("\n\n0.Thoat chuong trinh\n1.Them contact\n2.Xem tat ca contact\n3.Tim kiem contact\n4.Xoa contact theo vi tri\n5.Xuat danh sach theo ten tang dan\nNhap lua chon cua ban: ");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:
		    nhapContact();
		    break;
		case 2:
    		hienThiContact();
    		break;
    	case 3:
    		find();
    		break;
    	case 4:
    		delContact();
    		hienThiContact();
    		break;
    	case 5:
    		printAsc(c, dem);	
    		break;
	}
	}
	
	
	
	


    return 0;
}

