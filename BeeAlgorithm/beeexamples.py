# -*- coding: utf-8 -*-
import random
import math

import pybee


class spherebee(pybee.floatbee):
    """Функция - сумма квадратов по каждой координате"""

    # Количество координат
    count = 4

    @staticmethod
    def getstartrange():
        return [150.0] * spherebee.count

    @staticmethod
    def getrangekoeff():
        return [0.98] * spherebee.count

    def __init__(self):
        pybee.floatbee.__init__(self)

        self.minval = [-150.0] * spherebee.count
        self.maxval = [150.0] * spherebee.count

        self.position = [random.uniform(self.minval[n], self.maxval[n]) for n in range(spherebee.count)]
        self.calcfitness()

    def calcfitness(self):
        self.fitness = 0.0
        for val in self.position:
            self.fitness -= val * val