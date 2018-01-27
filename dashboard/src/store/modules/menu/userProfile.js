import lazyLoading from './lazyLoading'

export default {
  name: 'User Profile',
  path: '/user-profile',
  component: lazyLoading('user-profile/UserProfile'),
  meta: {
    default: true,
    title: 'menu.userProfile',
    iconClass: 'vuestic-icon vuestic-icon-user'
  }
}
