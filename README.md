![](https://img.shields.io/badge/License-MIT-green.svg)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD$%E2%82%AC%20%D0%9D%D0%B0%20%D0%BF%D0%B8%D0%B2%D0%BE-%D1%81%20%D1%80%D1%8B%D0%B1%D0%BA%D0%BE%D0%B9-red.svg)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/youtube/channel/subscribers/UCgtAOyEQdAyjvm9ATCi_Aig?style=social)](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig)

# GyverPortal
Простой конструктор веб интерфейса для esp8266 и ESP32
- Простой конструктор - делаем страницы без знаний HTML и CSS
- Библиотека является обёрткой для стандартной ESP8266WebServer
- Позволяет быстро создать вебморду для управления и настройки своего девайса
- Компактный читаемый код в "скетче", никаких внешних обработчиков и лямбда-функций
- Конструктор использует стандартные HTML формы, CSS и javascript
- Элементы конструктора хранятся во Flash памяти
- Никаких глобальных буферов, всё генерируется на лету
- Приятный дизайн из коробки + тёмная тема
- Адаптировано под мобильные устройства и ПК
- Встроенные инструменты для удобного парсинга значений с формы
- Возможность настроить автоматическое обновление значений переменных по действию со страницы
- Встроенные жабаскрипты для AJAX, работа без обновления всей страницы:
  - Клики по компонентам, изменение их значений
  - Обновление компонентов по таймеру
  - График в реальном времени
- Компоненты конструктора:
  - Заголовок
  - Подпись
  - Разделитель
  - Перенос строки
  - Блок для объединения компонентов
  - Поле ввода текста
  - Поле ввода пароля
  - Галочка (чекбокс)
  - Выключатель
  - Слайдер
  - Выбор времени
  - Выбор даты
  - Селектор (дропбокс)
  - Кнопка
  - "Светодиод" индикатор
  - График (смартфон должен быть подключен к интернету)
  
![demo](/docs/demoBig.png)  

### Совместимость
esp8266, esp32

## Содержание
- [Установка](#install)
- [Инициализация](#init)
- [Документация](#docs)
- [Использование](#usage)
- [Примеры](#example)
- [Версии](#versions)
- [Баги и обратная связь](#feedback)

<a id="install"></a>
## Установка
- Библиотеку можно найти по названию **GyverPortal** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/GyverPortal/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)

<a id="init"></a>
## Инициализация
`GyverPortal portal;`

<a id="docs"></a>
## Документация
<details>
<summary>Функции конструктора</summary>

```cpp
// создание страницы
BUILD_BEGIN(строка);                // начать построение. Добавляет начальный HTML код
BUILD_END();                        // завершить построение. Добавляет завершающий HTML код и открывает страницу

// темы
add.THEME(тема);                    // установить тему
GP_DEFAULT  - стандартная тема
GP_LIGHT    - светлая тема
GP_DARK     - тёмная тема

// создание формы
add.FORM_BEGIN(имя);                // начать форму с именем (имя)
add.FORM_END();                     // завершить форму

// пустая форма с одной кнопкой
add.FORM_SUBMIT(имя, текст);        // форма с именем (имя) кнопкой (текст)

add.AJAX_UPDATE(список, период);    // передать список обновления компонентов
add.AJAX_PLOT(имя, заголовок, подпись Y, период);   // динамический график (см. пример ajaxPlot)
add.PLOT_LIGHT(id, подпись Y, подписи, значения, кол-во осей);  // статический график (см. пример staticPlot)
add.PLOT_DARK();                    // тёмный статический график (см. пример staticPlot)

// компоненты формы
add.BUTTON(имя, текст);             // кнопка
add.NUMBER(имя, подсказка, число);  // поле ввода текста, число
add.TEXT(имя, подсказка, текст);    // поле ввода текста
add.PASS(имя, подсказка, текст);    // поле ввода пароля
add.CHECK(имя);                     // чекбокс, умолч. выключен
add.CHECK(имя, состояние);          // чекбокс
add.SWITCH(имя);                    // выключатель, умолч. выключен
add.SWITCH(имя, состояние);         // выключатель
add.DATE(имя);                      // ввод даты, умолч. пустой
add.DATE(имя, GPdate);              // ввод даты
add.TIME(имя);                      // ввод времени, умолч. пустой
add.TIME(имя, GPtime);              // ввод времени
add.SELECT(имя, список);            // селектор (дропбокс), элементы списка разделены запятой
add.SELECT(имя, список, активный);  // + текущий активный пункт
add.SLIDER(имя, число, мин, макс);       // слайдер
add.SLIDER(имя, число, мин, макс, шаг);  // слайдер
add.COLOR(имя);                     // выбор цвета, умолч. чёрный
add.COLOR(имя, число);              // выбор цвета
add.SUBMIT(текст);                  // кнопка отправки формы
add.LED_RED(имя);                   // красный светодиод-индикатор
add.LED_GREEN(имя);                 // зелёный светодиод-индикатор

// прочее для оформления
add.TITLE(текст);                   // заголовок
add.TITLE(текст, имя);              // + имя компонента (для update())
add.LABEL(текст);                   // подпись (для кнопок, полей, чекбоксов итд)
add.LABEL(текст, имя);              // + имя компонента (для update())
add.LABEL(число);                   // подпись, число
add.LABEL(число, имя);              // + имя компонента (для update())
add.BREAK();                        // перенести строку
add.HR();                           // горизонтальный разделитель
add.BLOCK_BEGIN();                  // начать отрисовку блока
add.BLOCK_END();                    // завершить отрисовку блока

// создание кастомной страницы
GP_BUILD(строка);                   // запустить конструктор (можно вызывать где угодно)
GP_SHOW();                          // отобразить страницу (вызывать только внутри функции конструктора!)
add.PAGE_BEGIN();                   // начальный HTML код
add.PAGE_END();                     // завершающий HTML код
add.AJAX_CLICK();                   // обработчик кликов
```
</details>

<details>
<summary>Методы класса</summary>

```cpp
// система
void start();                       // запустить портал
void start(WIFI_AP);                // запустить портал с DNS сервером (для AP)
void stop();                        // остановить портал// показать свою страницу
void showPage(String&);             // показать свою страницу
void show();                        // вызвать конструктор и показать страницу

// подключение
void attachBuild(void*);            // подключить функцию-билдер страницы
void attachForm(void*);             // подключить функцию, которая вызывается при нажатии submit
void attachClick(void*);            // подключить функцию, которая вызывается при клике (кнопка, чекбокс, свитч, слайдер, селектор)
void attachUpdate(void*);           // подключить функцию, которая вызывается при AJAX обновлении со страницы

// опрос
bool tick();                        // тикер портала. Вернёт true, если портал запущен

bool form();                        // вернёт true, если было нажатие на любой submit
bool form(char* name);              // вернёт true, если был submit с указанной формы
String& formName();                 // получить имя теукщей submit формы

bool click();                       // вернёт true, если был клик по (кнопка, чекбокс, свитч, слайдер, селектор)
bool click(char* name);             // вернёт true, если был клик по указанному элементу
String& clickName();                // получить имя теукщего кликнутого компонента
const String& clickText();          // получить имя текст кликнутого компонента

bool update();                      // вернёт true, если было обновление
bool update(char* name);            // вернёт true, если было update с указанного компонента
String& updateName();               // вернёт имя обновлённого компонента
void answer(String& s);             // отправить ответ на обновление
void answer(int s);
void answer(char* s);

bool root();                        // вернёт true, если открыта главная страница (/)
String& uri();                      // адрес текущего запроса

// список автообновления
list.init(количество);              // инициализировать список, указать количество
list.clear();                       // очистить список
list.add(адрес, имя, тип);          // добавить переменную, указать имя компонента и тип
list.add(адрес, имя формы, имя, тип);   // добавить переменную, имя формы, указать имя компонента и тип

// типы для списка
T_CSTR      - массив char
T_STRING    - строка String
T_TIME      - время типа GPtime
T_DATE      - дата типа GPdate
T_CHECK     - boolean, для чекбокса
T_BYTE      - целое 1 байт
T_INT       - целое 4 байта
T_FLOAT     - float
T_COLOR     - целое 4 байта, для цвета

// парсеры
String getString(char* name);       // получить String строку с компонента name
char* getChars(char* name);         //получить char* строку с компонента name
void copyStr(char* name, char* dest);   // переписать char строку с компонента name к себе в dest
long getInt(char* name);            // получить целое число с компонента name
float getFloat(char* name);         // получить float число с компонента name
bool getCheck(char* name);          // получить состояние чекбокса с компонента name
GPdate getDate(char* name);         // получить дату с компонента name в формате GPdate
GPtime getTime(char* name);         // получить время с компонента name в формате GPtime
uint32_t getColor(char* name);      // получить цвет с компонента name
uint8_t getSelected(char* name, char* list);    // получить номер выбранного пункта в дроплисте list
```
</details>

<details>
<summary>Типы данных</summary>

```cpp
// структура для хранения даты
struct GPdate {
  uint16_t year;
  uint8_t month, day;
};

// структура для хранения времени
struct GPtime {
  uint8_t hour, minute;
};
```
</details>

<details>
<summary>Утилиты</summary>

```cpp
char* splitList(char* str);             // разделить строку на подстроки. Цыганские фокусы
int8_t inList(char* name, char* list);  // получить номер, под которым name входит в list (вида "val1,val2,val3")
int8_t inList(String& name, char* list);

void encodeDate(char* str, GPdate& d);  // склеить дату в строку str[11]
void encodeTime(char* str, GPtime& t);  // склеить время в строку str[6]
String encodeDate(GPdate& d);           // склеить дату в строку String
String encodeTime(GPtime& t);           // склеить время в строку String
GPdate decodeDate(char* str);           // разобрать строковую дату[11] в структуру
GPtime decodeTime(char* str);           // разобрать строковое время[6] в структуру

String encodeColor(uint32_t color);     // собрать цвет в String #rrggbb
uint32_t decodeColor(char* hex);        // разобрать цвет #rrggbb в число
```
</details>

### Таблица поддержки режимов работы компонентами

| Компонент/Вызов | form() | click() | update() |
| --------------- |:------:|:-------:|:--------:|
| TITLE           |        |         |    ✔    |
| LABEL           |        |         |    ✔    |
| BUTTON          |        |   ✔     |          |
| NUMBER          |   ✔   |   ✔     |    ✔    |
| TEXT            |   ✔   |   ✔     |    ✔    |
| PASS            |   ✔   |   ✔     |    ✔    |
| CHECK           |   ✔   |   ✔     |    ✔    |
| SWITCH          |   ✔   |   ✔     |    ✔    |
| DATE            |   ✔   |   ✔     |    ✔    |
| TIME            |   ✔   |   ✔     |    ✔    |
| SLIDER          |   ✔   |   ✔     |    ✔    |
| COLOR           |   ✔   |   +/-    |    ✔    |
| SELECT          |   ✔   |   ✔     |          |
| LED_RED         |   ✔   |          |    ✔    |
| LED_GREEN       |   ✔   |          |    ✔    |

* COLOR по сигналу click() не передаёт цвет

<a id="usage"></a>
## 1. Сервер
Библиотека может работать как в локальной сети (esp подключается к роутеру), так и в режиме точки доступа (смартфон подключается к esp).
### 1.1 Подключение к роутеру
```cpp
  WiFi.mode(WIFI_STA);
  WiFi.begin("login", "pass");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());
  // ...
  portal.begin();   // запускаем портал
```
Для подключения к порталу нужно зайти в браузере на IP адрес платы, который выдал ей роутер. В примере выше этот адрес выводится в монитор порта.

### 1.2 Создание точки
В этом режиме при запуске портала нужно передать **WIFI_AP** для запуска DNS сервера
```cpp
  WiFi.mode(WIFI_AP);
  WiFi.softAP("My Portal");
  portal.begin(WIFI_AP);   // запускаем портал с настройкой на режим AP
```
На стандартных настройках IP адрес для подключения в этом режиме будет *192.168.4.1*

### 1.3 Тикер
В GyverPortal используется стандартная библиотека *ESP8266WebServer*, поэтому 
для обеспечения работы сервера нужно вызывать `portal.tick()` в цикле программы. Возвращает `true`, если сервер запущен в данный момент.

### 1.4 Создаём GyverPortal глобально
```cpp
GyverPortal portal;
void build() {}

void setup() {
  // подключаемся к сети
  portal.attachBuild(build);
  portal.start();
}

void loop() {
  portal.tick();
  // опрос действий
}
```

### 1.5 Создаём GyverPortal локально
```cpp
void build() {}

void f() {
  GyverPortal portal;
  portal.attachBuild(build);
  portal.start();
  
  while (portal.tick()) {
    // опрос действий
  }
}
```
Для выхода из цикла можно вызвать `portal.stop()` по таймауту или сигналу с браузера.

## 2. Конструктор страниц
### 2.1. Создаём функцию конструктора
1. Создаём функцию вида: `void f()`. Далее в ней:
2. Создём пустую строку: `String s;`.
3. Запускаем конструктор: `BUILD_BEGIN(s)`. Передаём созданную строку. Здесь добавляется начальный HTML код.
4. (Опционально) применяем тему: `add.THEME(тема)`, доступные темы см. в документации.
5. Строим страницу, используя конструктор или прибавляя свои данные к строке.
6. Завершаем работу конструктора: `BUILD_END()`. Здесь добавляется завершающий HTML код и страница отправляется на сервер.

Шаблон функции конструктора:
```cpp
void build() {
  String s;
  BUILD_BEGIN(s);
  add.THEME(GP_LIGHT);
  // собираем страницу
  // ...
  BUILD_END();
}
```

### 2.2 Кастомная страница
Для создания полностью кастомной страницы нужно запустить конструктор `GP_BUILD(s)`, а после завершения построения вызвать `GP_SHOW()`. В чём отличие?
- `BUILD_BEGIN()` состоит из `GP_BUILD(s)`, `add.PAGE_BEGIN()` и `add.AJAX_CLICK()`
- `BUILD_END()` состоит из `add.PAGE_END()` и `GP_SHOW()`

### 2.3 Подключаем функцию конструктора
Передаём в библиотеку нашу функцию-конструктор страницы:
```cpp
portal.attachBuild(build);
```
Библиотека сама будет вызывать её, когда потребуется отобразить страницу. Функций-конструкторов (а следовательно и страниц) может быть несколько и их можно переключать.


## 3. Использование форм
### 3.1 Собираем страницу с формами
Основная суть использования форм:
- Форма имеет своё уникальное имя, должно начинаться с **/**
- Внутри формы может быть сколько угодно элементов, но только одна кнопка типа **SUBMIT**
- При нажатии на SUBMIT esp получает имя формы и данные из всех элементов внутри этой формы
- При нажатии на SUBMIT страница перезагружается, поэтому значения компонентов страницы нужно хранить в переменных и передавать при следующей сборке страницы

Пример с двумя формами, первая может передать текст из окна ввода, вторая - только факт нажатия кнопки:
```cpp
форма_1
    ввод текста
    кнопка submit
форма_1

форма_2
    кнопка submit
форма_2
```

В конструкторе GyverPortal это будет выглядеть так:
```cpp
void build() {
  String s;                     // создать строку
  BUILD_BEGIN(s);               // запустить конструктор
  add.THEME(GP_LIGHT);          // применить тему
  
  add.FORM_BEGIN("/login");     // начать форму, передать имя
  add.TEXT("txt", "Login", ""); // ввод текста, подсказка Login, текста нет
  add.BREAK();                  // перенос строки
  add.SUBMIT("Submit");         // кнопка Submit
  add.FORM_END();               // завершить форму
  
  add.FORM_BEGIN("/exit");      // начать форму, передать имя
  add.SUBMIT("Exit");           // кнопка Exit
  add.FORM_END();               // завершить форму
  
  BUILD_END();                  // завершить построение
}
```
Результат работы конструктора:  
![demo](/docs/demo.png)  
Все инструменты конструктора описаны в документации выше.

### 3.2 Опрос действий
- При нажатии любой кнопки типа *SUBMIT* в браузере функция `form()` вернёт `true`
- Функция должна опрашиваться после `tick()`
- Для поиска формы, с которой пришёл сигнал, используем `form(имя)` - вернёт `true`, если имя совпало
```cpp
portal.tick();
if (portal.form()) {
  if (portal.form("/login")) Serial.println("Login!");
  if (portal.form("/exit")) Serial.println("Exit!");
}
```

### 3.3 Подключение обработчика
Вместо ручного опроса `form()` можно подключить свою функцию вида `void f(GyverPortal*)`, она будет вызвана при нажатии на любой SUBMIT. 
Эту функцию нужно будет передать в `attachForm()`.
```cpp
void myAction(GyverPortal* p) {
  // имеем доступ к объекту портала, который отправил вызов
  if (p -> form("/exit")) Serial.println("exit");
}

void setup() {
  portal.attachForm(myAction);
}
```


### 3.4 Парсинг данных
В библиотеке реализованы готовые инструменты для полученя данных из компонентов формы (см. документацию выше). Например выведем в порт содержимое поля ввода текста:
```cpp
portal.tick();
if (portal.form()) {
  if (portal.form("/login")) {
    Serial.println(portal.getString("txt"));
    // где "txt" - имя компонента
  }
}
```

## 4. Использование кликов
### 4.1 Отличие от форм
В библиотеке реализован механизм, позволяющий обрабатывать действия на странице без её перезагрузки (как при использовании форм):
- Форма позволяет по нажатию одной кнопки получить значения с нескольких компонентов. Страница перезагрузится.
- Клик позволяет получить текущее (изменённое) значение только с кликнутого компонента. *Страница не перезагрузится*.

### 4.2 Опрос действий
- При клике по некоторым компонентам или изменении их значения (см. таблицу в документации) функция `click()` вернёт `true`
- Функция должна опрашиваться после `tick()`
- Для поиска компонента, с которого пришёл сигнал, используем `click(имя)` - вернёт `true`, если имя совпало
```cpp
portal.tick();
if (portal.click()) {
  if (portal.click("mybutton")) Serial.println("Click!");
}
```

### 4.3 Подключение обработчика
Вместо ручного опроса `click()` можно подключить свою функцию вида `void f(GyverPortal*)`, она будет вызвана при нажатиях на компоненты. 
Эту функцию нужно будет передать в `attachClick()`.
```cpp
void myClick(GyverPortal* p) {
  // имеем доступ к объекту портала, который отправил вызов
  if (p -> click("mybutton")) Serial.println("Click!");
}

void setup() {
  portal.attachClick(myClick);
}
```

### 4.4 Парсинг данных
Парсинг данных от кликов можно производить при помощи тех же функций, что и для форм.

## 5. Использование обновлений
В библиотеке реализован механизм скриптовых запросов со страницы по таймеру. Это позволяет обновлять значения некоторых компонентов и надписей 
(см. таблицу в документации) без обновления страницы в браузере.

### 5.1 Подключение обновлений
Для включения режима обновлений нужно добавить в начало страницы блок *AJAX_UPDATE*:
```cpp
void build() {
  String s;
  BUILD_BEGIN(s);
  add.AJAX_UPDATE("name1,name2,name3");
  // ...
  add.LABEL("NAN", "val");  // будем обновлять текст
  BUILD_END();
}
```

- Функция AJAX_UPDATE принимает список имён компонентов, разделённых запятой.
- ПРОБЕЛ ПОСЛЕ ЗАПЯТОЙ НЕ СТАВИМ. 
- Также можно указать период запросов на обновления в миллисекундах `add.AJAX_UPDATE("name1,name2", 5000);`, по умолчанию - 1000 (1 секунда).
- Не все компоненты поддерживают режим обновлений (см. таблицу в документации).

### 5.2 Опрос обновлений
- При наступлении обновления функция `update()` вернёт `true`
- Функция должна опрашиваться после `tick()`
- Для поиска компонента, с которого пришёл сигнал, используем `update(имя)` - вернёт `true`, если имя совпало
- Нужно ответить на запрос обновления при помощи функции `answer()`. В неё передаётся актуальное значение для компонента
- Если не ответить на обновление до следующего вызова `tick()` - библиотека ответит пустым ответом, чтобы страница не зависла

```cpp
portal.tick();
if (portal.update()) {
  if (portal.update("val")) portal.answer(random(1000));
}
```

### 5.3 Подключение обработчика
Вместо ручного опроса `update()` можно подключить свою функцию вида `void f(GyverPortal*)`, она будет вызвана при обновлении любого компонента. 
Эту функцию нужно будет передать в `attachUpdate()`.
```cpp
void myUpdate(GyverPortal* p) {
  if (p -> update("val")) p -> answer(random(1000));
}

void setup() {
  portal.attachUpdate(myUpdate);
}
```


## 6. Автоматическое обновление переменных
**[См. примеры demoSubmitAuto и demoClickAuto]** Вместо ручного парсинга можно указать библиотеке переменные, 
которые будут автоматически получать новые значения с указанных компонентов страницы. *Это работает как для форм, так и для кликов.*
- Инициализируем список, вызвав `.list.init(количество)`, передаём размер списка в количестве переменных.
- Добавляем переменную по её адресу:
  - `.list.add(&переменная, имя, тип)` - с указанием имени компонента и его типа
  - `.list.add(&переменная, форма, имя, тип)` - с указанием имени формы, имени компонента и типа  
  
Указанные переменные обновят свои значения при действии с формы с указанным именем или при клике. 
Если имя формы не указано - компонент будет парситься при действии с любой формы. *Для работы с кликами не нужно указывать имя формы.*  

### 6.1 Поддержка фичи компонентами, связь с типами

| Тип данных    | Тип/Компонент | TEXT | PASS | CHECK | SWITCH | DATE | TIME | SLIDER | COLOR | SELECT |
| ------------- | ------------- |:----:|:----:|:-----:|:------:|:----:|:----:|:------:|:-----:|:------:|
| `char[]`      | T_CSTR        |  ✔  |  ✔   |       |        |  ✔  |  ✔  |   ✔   |   ✔   |   ✔   |
| `String`      | T_STRING      |  ✔  |  ✔   |       |        |  ✔  |  ✔  |   ✔   |   ✔   |   ✔   |
| `GPtime`      | T_TIME        |      |      |        |       |      |  ✔  |        |       |        |
| `GPdate`      | T_DATE        |      |      |        |       |  ✔  |      |        |       |        |
| `bool`        | T_CHECK       |      |      |  ✔    |   ✔   |      |      |        |       |        |
| `byte`, `char`| T_BYTE        |  ✔  |  ✔  |        |        |      |      |   ✔   |       |        |
| `int`, `long` | T_INT         |  ✔  |  ✔   |       |        |      |      |   ✔   |       |        |
| `float`       | T_FLOAT       |  ✔  |  ✔   |       |        |      |      |   ✔   |       |        |
| `uint32_t`    | T_COLOR       |      |      |       |        |      |      |        |   ✔   |        |


<a id="example"></a>
## Примеры
```cpp
```

<a id="versions"></a>
## Версии
- v1.0

<a id="feedback"></a>
## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!
