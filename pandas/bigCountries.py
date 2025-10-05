import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    # not recommended 
    # data = {
    #     "name": [],
    #     "population": [],
    #     "area": []
    # }
    # big_country = pd.DataFrame(data)
    # for index, country in world.iterrows():
    #     if (country["area"] >= 3000000 or country["population"] >= 25000000):
    #         new_b_country = pd.DataFrame([country[["name","population","area"]]])
    #         big_country = pd.concat([big_country, new_b_country], ignore_index=True) 

    # return big_country

    # This vectorized approach (Boolean Masking) is highly superior to iteration (loops) 
    # for large datasets as it processes entire columns at once using optimized code.
    is_big = (world["area"] >= 3000000) | (world["population"] >= 25000000)

    big_country = world[is_big][["name", "population", "area"]]

    return big_country