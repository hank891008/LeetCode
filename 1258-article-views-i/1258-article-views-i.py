import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    views = views.query("author_id == viewer_id")[['author_id']].drop_duplicates()
    views = views.rename(columns={'author_id': 'id'}).sort_values(['id'])
    return views