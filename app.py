import streamlit as st
from collections import deque

st.title("🚍 City Navigation System")
st.markdown("Find the shortest route between two cities using **BFS traversal**!")

city_map = {
    "Nashik": ["Pune", "Mumbai", "Aurangabad"],
    "Pune": ["Nashik", "Mumbai", "Satara"],
    "Mumbai": ["Nashik", "Pune", "Thane"],
    "Aurangabad": ["Nashik", "Jalna"],
    "Satara": ["Pune"],
    "Thane": ["Mumbai", "Kalyan"],
    "Jalna": ["Aurangabad", "Beed"],
    "Beed": ["Jalna"],
    "Kalyan": ["Thane"]
}

def bfs_shortest_path(graph, start, goal):
    visited = set()
    queue = deque([[start]])
    if start == goal:
        return [start]
    while queue:
        path = queue.popleft()
        node = path[-1]
        if node not in visited:
            neighbours = graph.get(node, [])
            for neighbour in neighbours:
                new_path = list(path)
                new_path.append(neighbour)
                queue.append(new_path)
                if neighbour == goal:
                    return new_path
            visited.add(node)
    return None

col1, col2 = st.columns(2)
with col1:
    start_city = st.selectbox("Select Starting City:", list(city_map.keys()))
with col2:
    end_city = st.selectbox("Select Destination City:", list(city_map.keys()))

if st.button("Find Route"):
    if start_city == end_city:
        st.warning("You are already in the same city 😄")
    else:
        path = bfs_shortest_path(city_map, start_city, end_city)
        if path:
            st.success(f"✅ Shortest path from **{start_city}** to **{end_city}** is:")
            st.markdown(" ➡️ ".join(path))
        else:
            st.error(f"No route found between {start_city} and {end_city} 😞")

with st.expander("📜 View City Connections"):
    for city, connections in city_map.items():
        st.write(f"**{city}** → {', '.join(connections)}")
        


