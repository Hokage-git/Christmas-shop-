#include <iostream>
#include <ctime>
#define Endl cout<<endl<<endl
#include <stdio.h>
#define randoms(X) (rand() * X / RAND_MAX)
#include <conio.h>

using namespace std;

char welcomes[3][255] = { "Привет, ","Здарова,дружище ","Здравствуйте, " };
int money = 200;

struct tov_info {
    char tovar[255];
    int value;
    int count;
};

tov_info database[10];

void rand_count(int arr[], int diapoz) {
    for (int i = 0; i < 10; i++) {
        arr[i] = 1+rand() * diapoz / RAND_MAX;
    }
}

void person() {
    int all_price = 0;
    int count_tov = 1 + rand() * 3 / RAND_MAX;
    int randome = randoms(10);
    int neponostiu = 1 + rand() * (database[randome].count/2) / RAND_MAX;
    int correct_price=0;
    int normal_price = 4 + rand() * 14 / RAND_MAX;


    while (database[randome].count == 0) {
        randome = randoms(10);
        while (neponostiu == database[randome].count)
            neponostiu = 1 + rand() * (database[randome].count / 2) / RAND_MAX;
    }

    if (database[randome].value > normal_price) {
        cout << "Слишком высокая цена,я не собираюсь брать товары по такой цене" << endl;
        return;
    }

    cout << "-" << welcomes[randoms(3)] << "мне нужны " << database[randome].tovar << ", я возьму " << ((database[randome].count-neponostiu)/2)<< endl;
    correct_price += database[randome].value * ((database[randome].count - neponostiu) / 2);
    database[randome].count -= ((database[randome].count - neponostiu) / 2);

    int tovs[4];
    tovs[0] = { randome };

    if (count_tov > 1) {
        for (int i = 1; i <= count_tov; i++) {
            randome = randoms(10);
            neponostiu = 1 + rand() * database[randome].count / RAND_MAX;
            tovs[i] = { randome };

            while (tovs[i] == tovs[i - 1]||tovs[i] == tovs[i-2]) {
                randome = randoms(10);
                neponostiu = 1 + rand() * database[randome].count / RAND_MAX;
                tovs[i] = { randome };
            }

            while (database[randome].count == 0) {
                randome = randoms(10);
                while (neponostiu == database[randome].count)
                    neponostiu = 1 + rand() * (database[randome].count / 2) / RAND_MAX;
            }

            cout << "Ещё бы я взял " << database[randome].tovar << ", штучек " << ((database[randome].count - neponostiu) / 2) << endl;
            correct_price += database[randome].value * ((database[randome].count - neponostiu) / 2);
            database[randome].count -= ((database[randome].count - neponostiu) / 2);
        }
    }
    
    cout <<"-" << "Без проблем с вас:"; cin >> all_price;
    if (correct_price < all_price) {
        cout << "Вы пытаетесь меня обмануть, я заплачу 1/3 от стоимости, иначе вызову полицию" << endl;
        money += all_price / 3;
    }
    else
    money += all_price;
    Endl;
}

int main()
{
    srand(time(NULL));
    system("color F0");
    setlocale(LC_ALL, "rus");
    char welcomes[3][255] = { "Привет, ","Здарова,дружище ","Здравствуйте, " };
    const char* tovar[10] = { "Рождественские ёлки","Имбирное печенье","Подарки","Конфеты","Герлянды","Венки из ёлок","Декорации для дома","Праздничные костюмы","Рождественские блюда","Алкоголь" };
    char names[20][255] = {"Артём","Элина","Максим","Роберт","Дима","Даша","Алина","Ксюша","Женя","Настя","Соня","Иван","Игорь","Алексей","Джонатан","Джозеф","Бруно","Кира","Джорно","Гарри"};
    int value[10];
    int count[10];
    char colors[5][255] = { "color 73","color 24","color 56","color D3","color 12" };
    int count_days = 0;
    const int max_days = 14;
    char chooser;
    int value_m = 0;

    for (int i = 0; i < 10; i++) {
        strcpy_s(database[i].tovar, tovar[i]);
    }

    cout << "\t\t\t\t\tДобро пожаловать в мини-игру!" << endl
        << "\t\t\t\t\t  Рождественский Магазинчик";

    Endl;

    cout << "Сюжет придельно прост:" << endl
        << "  Оставив вам 200 монет, ваш отец отправился в столицу,которая в 2 неделях езды от вашего города,чтобы купить подарки вам и вашей сестре." << endl
        << "Во время своего отсутвия он решил оставить на вас свой магазин.Вам нужно продавать рождественские товары гражданам" << endl
        << "вашего города и зарабатывать деньги на пропитание вам и вашей сестре.";

    Endl;

    cout << "Правила:" << endl
        << "1.Каждый день на личные раходы уходит 130 монет" << endl
        << "2.За день приходят от 2 до 4 покупателей" << endl
        << "3.Просто получайте удовольствие";
    Endl;
    cout << "Если вам хочется начать игру, то ";
    system("pause");

    system("cls");

    rand_count(count, 60);

    for (int i = 0; i < 10; i++)
        database[i].count = count[i];

    for (int i = 1; i <= max_days; i++) {
        if (money < 0) {
            system("cls");
            cout << "\t\t\t\t\t\t  Вы проиграли D:" << endl;
            cout << "\t\t\t\t\t\tБыло прожито " << i - 1 << " дней";
            Endl;
            return 0;
        }
        cout << "\t\t\t\t\t\t День " << i;
        Endl;
        cout << "У вас в наличии:" << endl
            << money << " Монет" << endl;

        if (i >= 2) {
            Endl;
            cout << "Ежедневный завоз товаров:";
            for (int j = 0; j < 10; j++) {
                rand_count(count, 10);
                database[j].count += count[j];
            }
            Endl;
        }

        for (int j = 1; j <= 10; j++) {
            cout << j << "." << database[j-1].tovar <<" - "<< database[j-1].count<< " Штук" << endl;
        }

        cout << "Выставьте цену на товары:" << endl;
        for (int j = 0; j < 10; j++) {
            cout << database[j].tovar << ":";
            cin >> database[j].value;
        }

        Endl;
        for (int j = 1; j < 2 + rand() * 4 / RAND_MAX; ++j) {
            cout << "А вот и "<< j <<" покупатель по имени " << names[randoms(20)] << endl;
            person();
        }
        money -= 130;
        system("cls");
    }

    cout << "Congrats people, или просто Поздравляю с прохождением игры!!!";
    int getch = 12;
    int getch1 = 11;
    char colores[255];
    system("cls");
    while (getch > getch1) {
        strcpy_s(colores, colors[randoms(5)]);
        system(colores);
    }
}
