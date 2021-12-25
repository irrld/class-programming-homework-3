/**
 * @file main.cpp (https://github.com/irrld/class-programming-homework-3)
 * @author Metehan Gezer (irrelevantdev@outlook.com)
 * @brief Algoritmalar ve Programlama Dersi Ödev 3 (g++ 10.2.0 kullanarak derlendi ve test edildi)
 * @version 0.1
 * @date 2021-12-25
 * 
 * @copyright Copyright (c) 2021
 */
#include <iostream>
#include <vector>
#include <iomanip> 
#include <string> 
#include <locale>

struct Book {
    int id;
    int year;
    std::string name;
    std::string author;
};


int main(){
    setlocale(LC_ALL, "TURKISH"); // Dili türkçe yapıyoruz böylece konsoldaki çıktılar türkçe karakterleri hatalı göstermiyor.
    int recordAmount; 
    std::cin >> recordAmount; // Kaç kayıt gireceğimizi kullanıcıdan alıyoruz 
    Book *books = new Book[recordAmount]; // Girilen sayı kadar dinamik bir dizi oluşturuyoruz, bu dizi heap'de deplolanıyor.
    for (int i = 0; i < recordAmount; i++) // Girilen kayıtları tek tek kullanıcıdan alıyoruz ve dizideki yerine yerleştiriyoruz
    {
        int year;
        std::string name, author;
        // Kitap kaydını okuyoruz
        std::cin >> year >> name >> author;
        // Bunları struct'a veriyoruz
        (books + i)->id = i + 1; // Daha sonra girdi sırası lazım olacak
        (books + i)->year = year;
        (books + i)->author = author;
        (books + i)->name = name;
    }
    int yearToView;
    std::cin >> yearToView; // Kullanıcıdan hangi yılı görüntüleyeceğimizi okuyoruz
    std::vector<Book> viewing; 
    for (int i = 0; i < recordAmount; i++)
    {
        Book *book = (books + i);
        // Kitabın yılı girilen yıl ile aynı ise kitabı vektöre ekliyoruz
        if (book->year == yearToView){
            viewing.push_back(*book); 
        }
    }
    std::cout << viewing.size() << std::endl; // Boyutu yazdırıyoruz
    int printIndex = 1;
    for (auto book = viewing.begin(); book < viewing.end(); book++)
    {
        // setw Bir sonraki çıktının her zaman verilen uzunlukta olmasını sağlıyor
        // Normalde bu çıktı sağa yaslanır fakat setw öncesinde left kullanıldığında sol tarafa yaslanabiliyor
        // Burada da bunu kullandım
        std::cout << std::left << std::setw(8) << (std::to_string(printIndex) + ".");
        std::cout << std::left << std::setw(8) << book->id;
        std::cout << std::left << std::setw(10) << book->year;
        std::cout << std::left << std::setw(20) << book->name;
        std::cout << std::left << std::setw(20) << book->author;
        std::cout << std::endl;
        printIndex++;
    }
    
    int i;
    std::cin >> i;
}