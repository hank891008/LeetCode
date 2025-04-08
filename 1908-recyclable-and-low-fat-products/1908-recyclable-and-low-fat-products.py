import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    products = products.query('low_fats.str.contains("Y") and recyclable.str.contains("Y")')[['product_id']]
    return products