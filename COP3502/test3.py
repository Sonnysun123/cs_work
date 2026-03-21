class student:
    count = 0
    def __init__(self,name,age):
        self.name = name
        self.age = age
        student.count += 1
    @classmethod
    def c(cls):
        print(student.count)

