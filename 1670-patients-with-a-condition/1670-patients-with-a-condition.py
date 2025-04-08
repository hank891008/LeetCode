import pandas as pd

def find_patients(patients: pd.DataFrame) -> pd.DataFrame:
    pattern = r'(^| )DIAB1'
    patients = patients.query("conditions.str.contains(@pattern)")
    return patients