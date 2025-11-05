import pandas as pd
import random
from faker import Faker

fake = Faker()
Faker.seed(0)
random.seed(0)

# Cantidad de registros mínimos
N_USUARIOS = 30
N_RUTAS = 25
N_ENTRENAMIENTOS = 50
N_RETOS = 10
N_PUBLICACIONES = 40

# ----------------------
# TABLA USUARIO
# ----------------------
usuarios = []
for i in range(N_USUARIOS):
    correo = f"user{i}@ghost.com"
    usuarios.append({
        "Usu_Correo": correo,
        "Usu_Username": fake.user_name(),
        "Usu_Contrasena": fake.sha256(),
        "Usu_Nombres": fake.first_name(),
        "Usu_Apellidos": fake.last_name(),
        "Usu_Edad": random.randint(15, 60),
        "Usu_FotoPerfil": None,
        "Usu_Descripcion": fake.sentence(),
        "Usu_FechaRegistro": fake.date_this_decade(),
        "Usu_Genero": random.choice(["Masculino", "Femenino", "Otro"])
    })
df_usuario = pd.DataFrame(usuarios)

# ----------------------
# TABLA ESTADO FÍSICO
# ----------------------
estado_fisico = []
for u in usuarios:
    estado_fisico.append({
        "Est_Fis_ID": fake.unique.random_int(min=1, max=10000),
        "Est_Fis_Peso": round(random.uniform(50, 90), 1),
        "Est_Fis_Altura": round(random.uniform(1.5, 2.0), 2),
        "Usu_Correo": u["Usu_Correo"]
    })
df_estado = pd.DataFrame(estado_fisico)

# ----------------------
# OBJETIVOS SEMANALES
# ----------------------
objetivos = []
for u in usuarios:
    objetivos.append({
        "Obj_Ent_Sem_ID": fake.unique.random_int(min=1, max=10000),
        "Obj_Ent_Sem_NumeroEntrenamientos": random.randint(2, 7),
        "Obj_Ent_Sem_Distancia": round(random.uniform(10, 50), 1),
        "Usu_Correo": u["Usu_Correo"]
    })
df_objetivos = pd.DataFrame(objetivos)

# ----------------------
# TABLA RUTA
# ----------------------
rutas = []
for i in range(N_RUTAS):
    rutas.append({
        "Rut_ID": i + 1,
        "Rut_Distancia": round(random.uniform(3, 15), 2)
    })
df_rutas = pd.DataFrame(rutas)

# ----------------------
# TABLA COORDENADA
# ----------------------
coordenadas = []
coor_id = 1
for r in rutas:
    for j in range(random.randint(5, 10)):
        coordenadas.append({
            "Coor_ID": coor_id,
            "Coor_Latitud": round(random.uniform(-90, 90), 6),
            "Coor_Longitud": round(random.uniform(-180, 180), 6),
            "Coor_Altitud": round(random.uniform(0, 3000), 1),
            "Rut_ID": r["Rut_ID"]
        })
        coor_id += 1
df_coordenadas = pd.DataFrame(coordenadas)

# ----------------------
# TABLA ENTRENAMIENTO
# ----------------------
entrenamientos = []
for i in range(N_ENTRENAMIENTOS):
    u = random.choice(usuarios)
    r = random.choice(rutas)
    entrenamientos.append({
        "Ent_ID": i + 1,
        "Ent_Fecha": fake.date_this_year(),
        "Ent_Hora_Inicio": fake.time(),
        "Ent_Duracion": f"00:{random.randint(20,90)}:{random.randint(0,59)}",
        #"Ent_Distancia": r["Rut_Distancia"],
        "Ent_Ritmo": round(random.uniform(4, 7), 2),
        "Ent_Max_Speed": round(random.uniform(15, 30), 2),
        "Ent_Avg_Speed": round(random.uniform(8, 12), 2),
        "Ent_Calorias": random.randint(200, 800),
        "Ent_CambioNivel": round(random.uniform(0, 200), 1),
        "Usu_Correo": u["Usu_Correo"],
        "Rut_ID": r["Rut_ID"]
    })
df_entrenamiento = pd.DataFrame(entrenamientos)

# ----------------------
# KM POR ENTRENAMIENTO
# ----------------------
kms = []
km_id = 1
for e in entrenamientos:
    for k in range(int(e["Ent_Distancia"])):
        kms.append({
            "Km_ID": km_id,
            "Km_Tiempo": f"00:{random.randint(4,8)}:{random.randint(0,59)}",
            "Km_Distancia": 1,
            "Ent_ID": e["Ent_ID"]
        })
        km_id += 1
df_km = pd.DataFrame(kms)

# ----------------------
# TABLA RETO
# ----------------------
retos = []
for i in range(N_RETOS):
    fecha_ini = fake.date_this_year()
    fecha_fin = fake.date_between(start_date=fecha_ini, end_date="+30d")
    retos.append({
        "Ret_Men_ID": i + 1,
        "Ret_Men_Distancia": round(random.uniform(30, 100), 1),
        "Ret_Men_Fecha_Inicio": fecha_ini,
        "Ret_Men_Fecha_Finalizacion": fecha_fin
    })
df_retos = pd.DataFrame(retos)

# ----------------------
# TABLA INSCRIPCION RETO
# ----------------------
inscripciones = []
for u in random.sample(usuarios, 20):
    inscripciones.append({
        "Ret_ID": random.choice(retos)["Ret_Men_ID"],
        "Usu_Correo": u["Usu_Correo"]
    })
df_inscripcion = pd.DataFrame(inscripciones)

# ----------------------
# TABLA PUBLICACION
# ----------------------
publicaciones = []
for i in range(N_PUBLICACIONES):
    u = random.choice(usuarios)
    r = random.choice(rutas)
    publicaciones.append({
        "Pub_ID": i + 1,
        "Pub_Likes": random.randint(0, 500),
        "Pub_ImagenRuta": None,
        "Pub_Privacidad": random.choice([0, 1, 2]),
        "Usu_Correo": u["Usu_Correo"],
        "Rut_ID": r["Rut_ID"]
    })
df_publicaciones = pd.DataFrame(publicaciones)

# ----------------------
# TABLAS CYCLING Y RUNNING
# ----------------------
cycling = []
running = []
for e in entrenamientos:
    if random.choice([True, False]):
        cycling.append({
            "Cyc_LongitudPedaleo": round(random.uniform(1.5, 3.0), 2),
            "Usu_Correo": e["Usu_Correo"],
            "Ent_ID": e["Ent_ID"],
            "Tipo": random.choice(["PR", "Normal"])
        })
    else:
        running.append({
            "Run_LongitudPaso": round(random.uniform(0.8, 1.5), 2),
            "Usu_Correo": e["Usu_Correo"],
            "Ent_ID": e["Ent_ID"],
            "Tipo": random.choice(["PR", "Normal"])
        })
df_cycling = pd.DataFrame(cycling)
df_running = pd.DataFrame(running)

# ----------------------
# TABLA ENTRENAMIENTOS_USUARIO
# ----------------------
ent_user = []
for e in entrenamientos:
    ent_user.append({
        "Usu_Correo": e["Usu_Correo"],
        "Ent_ID": e["Ent_ID"]
    })
df_ent_user = pd.DataFrame(ent_user)

# ----------------------
# TABLA SEGUIDOS
# ----------------------
seguidos = []
for _ in range(30):
    u1, u2 = random.sample(usuarios, 2)
    seguidos.append({
        "Usu_Correo1": u1["Usu_Correo"],
        "Usu_Correo2": u2["Usu_Correo"]
    })
df_seguidos = pd.DataFrame(seguidos)

# ----------------------
# EXPORTAR A EXCEL
# ----------------------
with pd.ExcelWriter("Ghost_Running_4FN.xlsx", engine="openpyxl") as writer:
    df_usuario.to_excel(writer, sheet_name="Usuario", index=False)
    df_estado.to_excel(writer, sheet_name="Estado_Fisico", index=False)
    df_objetivos.to_excel(writer, sheet_name="Objetivos_Semanal", index=False)
    df_rutas.to_excel(writer, sheet_name="Ruta", index=False)
    df_coordenadas.to_excel(writer, sheet_name="Coordenada", index=False)
    df_entrenamiento.to_excel(writer, sheet_name="Entrenamiento", index=False)
    df_km.to_excel(writer, sheet_name="Km", index=False)
    df_retos.to_excel(writer, sheet_name="Reto", index=False)
    df_inscripcion.to_excel(writer, sheet_name="Inscripcion_Reto", index=False)
    df_publicaciones.to_excel(writer, sheet_name="Publicacion", index=False)
    df_cycling.to_excel(writer, sheet_name="Cycling", index=False)
    df_running.to_excel(writer, sheet_name="Running", index=False)
    df_ent_user.to_excel(writer, sheet_name="Entrenamientos_Usuario", index=False)
    df_seguidos.to_excel(writer, sheet_name="Seguidos", index=False)

print("✅ Archivo Ghost_Running_4FN.xlsx generado con éxito.")