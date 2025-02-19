
uml_diagram = """@startuml
class Car {
  - make: String
  - model: String
  - year: int
  + start()
  + stop()
}

class Engine {
  - horsepower: int
  + getPower(): int
}

Car --> Engine : "has one"
@enduml
"""

def generate_uml(filename="sampleuml.uml"):
    with open(filename, "w") as f:
        f.write(uml_diagram)
    print(f"UML diagram written to {filename}")

if __name__ == "__main__":
    generate_uml()