class Luggage:
    def __init__(self, size, profit):
        self.size = size
        self.profit = profit
        self.eval = profit / size
        self.is_used = 0

    def set_is_used(self):
        self.is_used = 1

    def __eq__(self, other):
        if not isinstance(other, Luggage):
            return NotImplemented
        return (self.eval, self.size, self.profit) == (other.eval, other.size, other.profit)

    def __lt__(self, other):
        if not isinstance(other, Luggage):
            return NotImplemented
        return (self.eval, self.size, self.profit) < (other.eval, other.size, other.profit)

    def __ne__(self, other):
        return not self.__eq__(other)

    def __le__(self, other):
        return self.__lt__(other) or self.__eq__(other)

    def __gt__(self, other):
        return not self.__le__(other)

    def __ge__(self, other):
        return not self.__lt__(other)


def main():
    max_size = 25

    data = [[3, 3], [5, 7], [4, 6], [2, 3], [10, 13], [7, 9], [1, 2], [5, 6]]

    luggage_list = []

    for val in data:
        luggage = Luggage(val[0], val[1])
        luggage_list.append(luggage)

    luggage_list.sort(reverse=True)

    size = 0

    for luggage in luggage_list:
        if size + luggage.size > max_size:
            continue

        size += luggage.size
        luggage.set_is_used()

    for luggage in luggage_list:
        print(luggage.size, luggage.profit, luggage.is_used)

    print(size)


if __name__ == '__main__':
    main()
