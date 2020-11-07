class SymbolTable:

    def __init__(self):
        self.id = 1
        self.symboltable = {}

    def entry(self, value, type, typedata):
        self.symboltable[self.id] = [value, type, typedata]
        self.id += 1
        return self.id - 1

    def getById(self, id):
        return self.symboltable.get(id, [None, None, None])

    def getBySymbol(self, value):
        id = -1 
        for ids, value_list in self.symboltable.items():
            if value_list[0] == value:
                return ids

            return id