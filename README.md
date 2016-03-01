# Best logic minesweeper game

## Задание
Реализовать логическую игру "Сапер".

Игра будет происходить в оконном режиме на 3х вариантах поля на выбор пользователя (в зависимости от выбранного уровня сложности) по правилам,описанным ниже. Должно быть реализовано сохранение текущей игры и загрузка игры с последнего момента. Должен присутствовать таймер, считающий время, прошедшее с начала игры. Программа должна определять победителя и выводить на экран соответствующее сообщение.
## Описание игры:

---------Цель игры---------

Найти пустые ячейки, но не трогать ячейки, содержащие мины. Чем быстрее вы очистите всю доску, тем лучше будет результат.


---------Игровая доска---------

В игре «Сапер» есть три стандартные доски, каждая следующая сложнее предыдущей.

1)Новичок: 81 ячейка, 10 мин

2)Любитель: 256 ячеек, 40 мин

3)Профессионал: 480 ячеек, 99 мин


---------Правила игры---------

1)Если открыта ячейка с миной, игра проиграна.

2)Если открыта пустая ячейка, игра продолжается.

3)Если в ячейке указано число, оно показывает, сколько мин скрыто в восьми ячейках вокруг данной. Это число помогает понять, где находятся безопасные ячейки.

## Концепция (vision statement) ?? сложнаа
Создается с точки зрения заказчика и конечных пользователей. Цель артефакта -- описать, как должен выглядеть успешный результат проекта. Иначе говоря, если проект завершается успешно, то как в этом случае должен выглядеть готовый продукт? Какими он обладает ключевыми характеристиками и функциями и как они могуть помочь пользователям выполнять их задачи? Концепция определяет на уровне руководства, в каком случае руководство может признать, что цель работы достигнута.

## Минимально работоспособный продукт (Minimum viable product)
Консольное приложение реализующее взаимодействие с ядром игры. 
Возможные действия: 
   1) Отобразить информацию о поле (какие ячейки открыты, какие - нет, и сколько мин находятся рядом с выбранной ячейкой)
   2) Вскрыть ячейку или установить на ней флаг

Также это приложение должно определять конец игры и информировать об этом игрока.   

## Диаграмма прецедентов использования
!["this is a picture"](reports/UseCaseDiagram1.jpg)

## Диаграмма последовательностей
!["this is a picture"](reports/sequenceDiagram.jpg) 
## Диаграмма компонентов
!["this is a picture"](reports/ComponentDiagram.jpg) 
