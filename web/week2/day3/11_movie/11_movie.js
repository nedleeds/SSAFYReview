const moviesDiv = document.getElementById("movies")

import { getPopularMovies } from "../11_movie/11_api.js";
import { config } from "../11_movie/11_config.js";

export async function renderMovies() {
    const movies = await getPopularMovies()
    console.log(movies)
    moviesDiv.innerHTML = movies?.map(movie => renderSingleMovie(movie)).join("")
}

function renderSingleMovie(movie) {
    return (
        `
        <div class="col-4 col-lg-3 col-xl-2 p-1">
            <img src="${config.image_base_url + movie?.poster_path}" class="img-fluid" >
        </div>
        `
    )
}