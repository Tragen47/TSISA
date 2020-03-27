import matplotlib.pylab as pylab

import pybee
import beeexamples
import beetestfunc

if __name__ == "__main__":

    # Включаем интерактивный режим
    pylab.ion()


    ###################################################
    ##                     Параметры алгоритма
    ###################################################

    # Класс пчел, который будет использоваться в алгоритме

    beetype = beeexamples.spherebee

    # Количество пчел-разведчиков
    scoutbeecount = 300

    # Количество пчел, отправляемых на выбранные, но не лучшие участки
    selectedbeecount = 10

    # Количество пчел, отправляемые на лучшие участки
    bestbeecount = 30

    # Количество выбранных, но не лучших, участков
    selsitescount = 15

    # Количество лучших участков
    bestsitescount = 5

    # Количество запусков алгоритма
    runcount = 1

    # Максимальное количество итераций
    maxiteration = 10000

    # Через такое количество итераций без нахождения лучшего решения уменьшим область поиска
    max_func_counter = 10

    # Во столько раз будем уменьшать область поиска
    koeff = beetype.getrangekoeff()

    ###################################################

    for runnumber in range(runcount):
        currhive = pybee.hive(scoutbeecount, selectedbeecount, bestbeecount,
                              selsitescount, bestsitescount,
                              beetype.getstartrange(), beetype)

        # Начальное значение целевой функции
        best_func = -1.0e9

        # Количество итераций без улучшения целевой функции
        func_counter = 0

        for n in range(maxiteration):
            currhive.nextstep()

            if currhive.bestfitness > best_func:
                # Найдено место, где целевая функция лучше
                best_func = currhive.bestfitness
                func_counter = 0

                # Обновим рисунок роя пчел
                beetestfunc.plotswarm (currhive, 0, 1)

                print(f'\n*** iteration {runnumber + 1}/{n}')
                print(f'Best position: {str(currhive.bestposition)}')
                print(f'Best fitness: {str(currhive.bestfitness)}')
            else:
                func_counter += 1
                if func_counter == max_func_counter:
                    # Уменьшим размеры участков
                    currhive.range = [currhive.range[m] * koeff[m] for m in range(len(currhive.range))]
                    func_counter = 0

                    print(f'\n*** iteration {runnumber + 1}/{n}')
                    print(f'New range: {str(currhive.range)}')
                    print(f'Best position: {str(currhive.bestposition)}')
                    print(f'Best fitness: {str(currhive.bestfitness)}')
