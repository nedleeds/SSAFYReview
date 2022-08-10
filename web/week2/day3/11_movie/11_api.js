import { config } from "../11_movie/11_config.js"

const BASE_URL = config.api_base_url
const API_KEY = config.api_key

export async function getPopularMovies(page = 1) {
    let data = []
    try {
        const response = await fetch(`${BASE_URL}movie/popular?api_key=${API_KEY}&page=${page}`)
        const responseData = await response.json()
        console.log(responseData)
        data = responseData?.results
    } catch (error) {
        
    }
    return data
}