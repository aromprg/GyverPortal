/*
    Простой конструктор веб интерфейса для esp8266 и ESP32
    Документация:
    GitHub: https://github.com/GyverLibs/GyverPortal
    Возможности:
    - Позволяет быстро создать универсальную вебморду для управления и настройки электронного девайса
    - Создание многостраничных и динамических веб-интерфейсов в несколько строк кода на языке С++ прямо в скетче
    - Не требует знания HTML, CSS и JavaScript: все стили и скрипты уже заложены в библиотеке
    - Не требует подключения к Интернет
    - Не требует загрузки файлов в SPIFFS (но стили и скрипты можно загружать оттуда для ускорения работы)
    - Лёгкий вес, небольшое использование динамической памяти во время генерации страницы
    - Работает на базе стандартных библиотек esp, ничего дополнительно устанавливать не нужно
    - Относительно стильный дизайн, светлая и тёмная темы, возможность кастомизации некоторых компонентов
    - Встроенные модули:
      - Несколько десятков стандартных компонентов и инструментов вёрстки (кнопки, графики, слайдеры, таблички, файловый менеджер...)
      - Автоматизированная загрузка файлов из SPIFFS
      - Автоматизированное скачивание файлов в SPIFFS + кеширование
      - Взаимодействие с браузером: получение данных с компонентов, обновление данных на компонентах
      - Часы реального времени (на основе времени в браузере)
      - AJAX и jQuery (опционально) обновление значений на странице
      - Автоматический опрос и обновление переменных
      - Перезагрузка страницы из скетча
      - Авторизация на сервере по логину-паролю
      - DNS сервер (для работы как точка доступа)
      - mDNS (для открытия интерфейса по заданному адресу вместо IP)
      - OTA обновление прошивки и памяти через браузер или curl (возможна защита паролем)
*/
/*
    TODO
    канвас
    https://www.w3schools.com/html/html5_canvas.asp
    https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API/Tutorial/Drawing_shapes
    https://developer.mozilla.org/ru/docs/Web/API/Canvas_API/Tutorial/Pixel_manipulation_with_canvas
    https://www.w3schools.com/tags/tryit.asp?filename=tryhtml5_canvas_createimagedata
*/

#ifndef _GyverPortal_h
#define _GyverPortal_h
#include <Arduino.h>

#define GP_CACHE_PRD "max-age=86400"        // таймаут кеширования (умолч. 86400 - сутки)

#ifndef GP_NO_DNS
#include <DNSServer.h>
#endif

#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#ifndef GP_NO_MDNS
#include <ESP8266mDNS.h>
#endif
#else

#include <WiFi.h>
#include <WebServer.h>
#ifndef GP_NO_MDNS
#include <ESPmDNS.h>
#endif
#endif

#include "themes.h"
#include "log.h"
#include "objects.h"
#include "portal.h"
#include "builder.h"
#include "canvas.h"
#include "legacy.h"
#include "buildMacro.h"
#include "version.h"

#ifndef GP_NO_OTA
#include "CustomOTA.h"
#endif

#endif
