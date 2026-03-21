from pakuri import *
class Pakudex:
    def __init__(self, capacity = 20):
        self.capacity = capacity
        self.size = 0
        self.species_list = []

    def get_size(self):
        return len(self.species_list)

    def get_capacity(self):
        return self.capacity

    def get_species_array(self):
        if len(self.species_list) == 0:
            return None
        return [a.get_species() for a in self.species_list]

    def get_stats(self, species):
        for a in self.species_list:
            if a.get_species() == species:
                return [a.get_attack(), a.get_defense(), a.get_speed()]
        return None

    def sort_pakuri(self):
        self.species_list.sort()

    def add_pakuri(self, species):
        if self.get_stats(species) is None:
            self.species_list.append(Pakuri(species))
            return True
        return False

    def evolve_species(self, species):
        for a in self.species_list:
            if a.get_species() == species:
                a.evolve()
                return True
        return False