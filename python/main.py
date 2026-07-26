
class data:
    def __init__(self, provincia, casos):
        self.provincia = provincia
        self.casos = casos

    def get_provincia(self):
        return self.provincia

    def get_casos(self):
        return self.casos
    

class Grafo:
    def __init__(self):
        self.vertices = []
        self.aristas = []