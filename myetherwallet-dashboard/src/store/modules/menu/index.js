import * as types from '../../mutation-types'
import dashboard from './dashboard'
import userProfile from './userProfile'
import myContracts from './myContracts'
import transactions from './transactions'
import tutorials from './tutorials'
import feedback from './feedback'

const state = {
  items: [
    dashboard,
    userProfile,
    myContracts,
    transactions,
    tutorials,
    feedback
  ]
}

const mutations = {
  [types.TOGGLE_EXPAND_MENU_ITEM] (state, payload) {
    let menuItem = payload.menuItem
    let expand = payload.expand
    if (menuItem.children && menuItem.meta) {
      menuItem.meta.expanded = expand
    }
  }
}

const actions = {
  toggleExpandMenuItem ({commit}, payload) {
    commit(types.TOGGLE_EXPAND_MENU_ITEM, payload)
  }
}

export default {
  state,
  mutations,
  actions
}
