## Review 7/3/2016

### Замечания, рекомендации.
  1. В концепции README.md: профессианал -> профессионал
  2. В папку reports необходимо загрузить исходники диаграмм
  3. Откомментируйте все header-файлы в нотации doxygen
  4. Используйте контейнеры STL вместо массивов в стиле C
  5. Вместо комментариев в стиле "Для справки что значат цифры в массиве..." лучше воспользоваться перечислением enum
  6. sources/Minesweeper/ConsApp/main.cpp: "QCoreApplication a(argc, argv);" и "return a.exec();" мне не ясно
  7. sources/Minesweeper/ConsApp/mainmenu.cpp: зачем отдельный файл для метода класса Application?
  8. sources/Minesweeper/ConsApp/application.h: почему все public? Особенно поле difficult
  9. sources/Minesweeper/ConsApp/main.cpp: используйте для счетчиков i и j тип size_t
  10. К методам вроде getField(); добавляйте const
  11. В Core ничего не понятно в целом, в GuiApp лично мне, так же можете начать писать тесты
